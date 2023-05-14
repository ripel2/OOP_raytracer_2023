/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** Parser
*/

#include "Parser.hpp"

#include "MaterialBuilder.hpp"
#include "LightBuilder.hpp"
#include "ObjectBuilder.hpp"

RayTracer::Parser::Parser(RayTracer::PluginLoader *loader)
    : _loader(loader), _imageWidth(0), _imageHeight(0), _scene(nullptr), _renderer(nullptr), _materials()
{
}

RayTracer::Parser::~Parser()
{
    if (_scene)
        _scene.reset();
    if (_renderer)
        _renderer.reset();
}

void RayTracer::Parser::parse(const std::string &path)
{
    libconfig::Config cfg;
    libconfig::Setting *root;

    try {
        cfg.readFile(path.c_str());
        root = &cfg.getRoot();
    } catch (const libconfig::FileIOException &fioex) {
        throw RayTracer::ParserError("I/O error while reading file.");
    } catch (const libconfig::ParseException &pex) {
        throw RayTracer::ParserError("Parse error at line " + std::to_string(pex.getLine()) + ": " + pex.getError());
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw RayTracer::ParserError("Setting not found: " + std::string(nfex.what()));
    }
    try {
        _scene = std::make_unique<RayTracer::Scene>();

        _parseCamera(*root);
        _parseRenderer(*root);
        _parseMaterials(*root);
        _parseLights(*root);
        _parseObjects(*root);
        _isFileParsedChanged = false;
        _fileParsed = path;
        _fileLastModificationDate = _getFileLastModificationDate();
    } catch (const RayTracer::ParserError &e) {
        throw e;
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw RayTracer::ParserError("Needed setting not found: " + std::string(nfex.getPath()));
    }
}

std::size_t RayTracer::Parser::getImageHeight() const
{
    return _imageHeight;
}

std::size_t RayTracer::Parser::getImageWidth() const
{
    return _imageWidth;
}

std::unique_ptr<RayTracer::Scene> RayTracer::Parser::getScene()
{
    return std::move(_scene);
}

std::unique_ptr<RayTracer::IRenderer> RayTracer::Parser::getRenderer()
{
    return std::move(_renderer);
}

double RayTracer::Parser::_getDouble(const libconfig::Setting &setting) const
{
    if (setting.getType() == libconfig::Setting::Type::TypeInt) {
        int value = setting;
        return static_cast<double>(value);
    } else if (setting.getType() == libconfig::Setting::Type::TypeInt64) {
        long long value = setting;
        return static_cast<double>(value);
    }
    return setting;
}

int RayTracer::Parser::_getInt(const libconfig::Setting &setting) const
{
    if (setting.getType() == libconfig::Setting::Type::TypeFloat) {
        double value = setting;
        return static_cast<int>(value);
    } else if (setting.getType() == libconfig::Setting::Type::TypeInt64) {
        long long value = setting;
        return static_cast<int>(value);
    }
    return setting;
}

std::string RayTracer::Parser::_getFileLastModificationDate()
{
    struct stat result;
    int ret = stat(_fileParsed.c_str(), &result);

    if (ret == -1)
        throw RayTracer::ParserError("Cannot get file last modification date");
    return std::to_string(result.st_mtime);
}

void RayTracer::Parser::_checkFileParsedChanged()
{
    if (_fileLastModificationDate != _getFileLastModificationDate()) {
        this->parse(_fileParsed);
    }
}

void RayTracer::Parser::_parseCamera(const libconfig::Setting &root)
{
    const libconfig::Setting &camera = root["camera"];

    if (!camera.isGroup())
        throw RayTracer::ParserError("Camera must be a group");
    if (!(camera["origin"].isArray() || camera["origin"].isList()) || camera["origin"].getLength() != 3)
        throw RayTracer::ParserError("Camera origin must be a list of three values");
    if (!(camera["lookAt"].isArray() || camera["lookAt"].isList()) || camera["lookAt"].getLength() != 3)
        throw RayTracer::ParserError("Camera lookAt must be a list of three values");
    if (!(camera["up"].isArray() || camera["up"].isList()) || camera["up"].getLength() != 3)
        throw RayTracer::ParserError("Camera up must be a list of three values");
    if (!camera["vfov"].isNumber())
        throw RayTracer::ParserError("Camera vfov must be a number");
    if (!camera["aspectWidth"].isNumber())
        throw RayTracer::ParserError("Camera aspectWidth must be a number");
    if (!camera["aspectHeight"].isNumber())
        throw RayTracer::ParserError("Camera aspectHeight must be a number");

    Math::Point<3> origin({_getDouble(camera["origin"][0]), _getDouble(camera["origin"][1]), _getDouble(camera["origin"][2])});
    Math::Point<3> lookAt({_getDouble(camera["lookAt"][0]), _getDouble(camera["lookAt"][1]), _getDouble(camera["lookAt"][2])});
    Math::Vector<3> up({_getDouble(camera["up"][0]), _getDouble(camera["up"][1]), _getDouble(camera["up"][2])});
    double vfov = _getDouble(camera["vfov"]);
    double aspectRatio = _getDouble(camera["aspectWidth"]) / _getDouble(camera["aspectHeight"]);
    std::unique_ptr<RayTracer::Camera> cameraPtr = std::make_unique<RayTracer::Camera>(origin, lookAt, up, vfov, aspectRatio);
    _scene->setCamera(cameraPtr);
}

void RayTracer::Parser::_parseRenderer(const libconfig::Setting &root)
{
    const libconfig::Setting &renderer = root["renderer"];

    if (!renderer["type"].getType() == libconfig::Setting::Type::TypeString)
        throw RayTracer::ParserError("Renderer type must be a string");
    if (!renderer["width"].isNumber())
        throw RayTracer::ParserError("Renderer width must be a number");
    if (!renderer["height"].isNumber())
        throw RayTracer::ParserError("Renderer height must be a number");

    std::string lowerType = renderer["type"];
    std::transform(lowerType.begin(), lowerType.end(), lowerType.begin(), [](unsigned char c) { return std::tolower(c); });

    _imageWidth = _getInt(renderer["width"]);
    _imageHeight = _getInt(renderer["height"]);

    if (lowerType == "ppmrenderer") {
        _renderer = std::make_unique<RayTracer::PPMRenderer>(renderer["filename"]);
    } else if (lowerType == "sfmlrenderer") {
        _renderer = std::make_unique<RayTracer::SfmlRenderer>(_imageWidth, _imageHeight, *this);
    } else {
        throw RayTracer::ParserError("Unknown renderer type: " + renderer["type"]);
    }
}

void RayTracer::Parser::_parseMaterials(const libconfig::Setting &root)
{
    if (!root["materials"].isArray() && !root["materials"].isList())
        throw RayTracer::ParserError("Materials must be a list");
    std::size_t size = root["materials"].getLength();
    for (std::size_t i = 0; i < size; i++) {
        const libconfig::Setting &material = root["materials"][i];

        _parseMaterial(material);
    }
}

void RayTracer::Parser::_parseMaterial(const libconfig::Setting &setting)
{
    std::unique_ptr<RayTracer::IMaterial> material = _loader->getMaterialFactory().createInstance(setting["type"]);
    RayTracer::MaterialBuilder builder(material.get());
    std::string name = setting["name"];
    std::string colors[] = {"color"};
    std::string doubles[] = {"fuzz", "fuzziness", "albedo", "refraction", "refractionIndex", "refraction_index"};

    for (const std::string &param: colors) {
        if (setting.exists(param)) {
            const libconfig::Setting &cparam = setting[param.c_str()];
            if (!(cparam.isArray() || cparam.isList()) || cparam.getLength() != 3)
                throw RayTracer::ParserError("Material " + param + " must be a list of three values");
            builder.set(param, RayTracer::Color({_getDouble(cparam[0]), _getDouble(cparam[1]), _getDouble(cparam[2])}));
        }
    }
    for (const std::string &param: doubles) {
        if (setting.exists(param)) {
            builder.set(param, _getDouble(setting[param.c_str()]));
        }
    }
    _materials[name] = std::move(material);
}

void RayTracer::Parser::_parseLights(const libconfig::Setting &root)
{
    if (!root["lights"].isArray() && !root["lights"].isList())
        throw RayTracer::ParserError("Lights must be a list");
    std::size_t size = root["lights"].getLength();
    for (std::size_t i = 0; i < size; i++) {
        const libconfig::Setting &light = root["lights"][i];

        _parseLight(light);
    }
}

void RayTracer::Parser::_parseLight(const libconfig::Setting &setting)
{
    std::unique_ptr<RayTracer::ILight> light = _loader->getLightFactory().createInstance(setting["type"]);

    RayTracer::LightBuilder builder(light.get());
    std::string colors[] = {"color"};
    std::string doubles[] = {"intensity", "shadow_ray_offset", "shadowRayOffset", "shadowRayBias", "shadow_ray_bias"};
    std::string points[] = {"position"};
    std::string vectors[] = {"direction"};
    std::string ints[] = {"shadowRayCount", "shadow_ray_count"};


    for (const std::string &param: colors) {
        if (setting.exists(param)) {
            const libconfig::Setting &cparam = setting[param.c_str()];
            if (!(cparam.isArray() || cparam.isList()) || cparam.getLength() != 3)
                throw RayTracer::ParserError("Light " + param + " must be a list of three values");
            builder.set(param, RayTracer::Color({_getDouble(cparam[0]), _getDouble(cparam[1]), _getDouble(cparam[2])}));
        }
    }
    for (const std::string &param: doubles) {
        if (setting.exists(param)) {
            builder.set(param, _getDouble(setting[param.c_str()]));
        }
    }
    for (const std::string &param: points) {
        if (setting.exists(param)) {
            const libconfig::Setting &cparam = setting[param.c_str()];
            if (!(cparam.isArray() || cparam.isList()) || cparam.getLength() != 3)
                throw RayTracer::ParserError("Light " + param + " must be a list of three values");
            builder.set(param, Math::Point<3>({_getDouble(cparam[0]), _getDouble(cparam[1]), _getDouble(cparam[2])}));
        }
    }
    for (const std::string &param: vectors) {
        if (setting.exists(param)) {
            const libconfig::Setting &cparam = setting[param.c_str()];
            if (!(cparam.isArray() || cparam.isList()) || cparam.getLength() != 3)
                throw RayTracer::ParserError("Light " + param + " must be a list of three values");
            builder.set(param, Math::Vector<3>({_getDouble(cparam[0]), _getDouble(cparam[1]), _getDouble(cparam[2])}));
        }
    }
    for (const std::string &param: ints) {
        if (setting.exists(param)) {
            builder.set(param, _getInt(setting[param.c_str()]));
        }
    }
    _scene->addLight(light);
}

void RayTracer::Parser::_parseObjects(const libconfig::Setting &root)
{
    if (!root["objects"].isArray() && !root["objects"].isList())
        throw RayTracer::ParserError("Objects must be a list");
    std::size_t size = root["objects"].getLength();
    for (std::size_t i = 0; i < size; i++) {
        const libconfig::Setting &object = root["objects"][i];

        _parseObject(object);
    }
}

void RayTracer::Parser::_parseObject(const libconfig::Setting &setting)
{
    std::unique_ptr<RayTracer::IObject> object = _loader->getObjectFactory().createInstance(setting["type"]);
    RayTracer::ObjectBuilder builder(object.get());
    std::string points[] = {"position"};
    std::string vectors[] = {"rotation", "translation", "scale", "normal", "distance"};
    std::string doubles[] = {"radius", "height", "inner_radius", "innerRadius"};
    std::string matNames[] = {"material"};

    for (const std::string &param: points) {
        if (setting.exists(param)) {
            const libconfig::Setting &cparam = setting[param.c_str()];
            if (!(cparam.isArray() || cparam.isList()) || cparam.getLength() != 3)
                throw RayTracer::ParserError("Object " + param + " must be a list of three values");
            builder.set(param, Math::Point<3>({_getDouble(cparam[0]), _getDouble(cparam[1]), _getDouble(cparam[2])}));
        }
    }
    for (const std::string &param: vectors) {
        if (setting.exists(param)) {
            const libconfig::Setting &cparam = setting[param.c_str()];
            if (!(cparam.isArray() || cparam.isList()) || cparam.getLength() != 3)
                throw RayTracer::ParserError("Object " + param + " must be a list of three values");
            builder.set(param, Math::Vector<3>({_getDouble(cparam[0]), _getDouble(cparam[1]), _getDouble(cparam[2])}));
        }
    }
    for (const std::string &param: doubles) {
        if (setting.exists(param)) {
            builder.set(param, _getDouble(setting[param.c_str()]));
        }
    }
    for (const std::string &param: matNames) {
        if (setting.exists(param)) {
            std::shared_ptr<RayTracer::IMaterial> material = _materials[setting[param.c_str()].c_str()];
            if (!material)
                throw RayTracer::ParserError("Material " + std::string(setting[param.c_str()].c_str()) + " does not exist");
            builder.set(param, material);
        }
    }
    if (!setting.exists("material"))
        throw RayTracer::ParserError("Object must have a material");
    _scene->addObject(object);
}

std::size_t RayTracer::Parser::getSamplesPerPixel() const
{
    return _samplesPerPixel;
}
