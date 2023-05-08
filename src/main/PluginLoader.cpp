/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** PluginLoader
*/

#include "PluginLoader.hpp"

void RayTracer::PluginLoader::LoadPlugins(const std::string &path)
{
    try {
        for (const auto &entry : std::filesystem::directory_iterator(path)) {
            if (entry.path().extension() == ".so") {
                pluginType_t type = OBJECT;

                try {
                    DLLoader<pluginType_t> loader(entry.path());
                    loader.loadInstance("getType");
                    type = *(loader.getInstance().get());
                } catch (const DLLoaderError &e) {
                    throw PluginLoaderError("Error while loading plugin: " + entry.path().string() + "\n" + e.what());
                }
                switch (type) {
                    case OBJECT:
                        try {
                            LoadPlugin(entry.path(), _objectFactory);
                        } catch (const DLLoaderError &e) {
                            throw PluginLoaderError("Error while loading plugin: " + entry.path().string() + "\n" + e.what());
                        }
                        break;
                    case LIGHT:
                        try {
                            LoadPlugin(entry.path(), _lightFactory);
                        } catch (const DLLoaderError &e) {
                            throw PluginLoaderError("Error while loading plugin: " + entry.path().string() + "\n" + e.what());
                        }
                        break;
                    case MATERIAL:
                        try {
                            LoadPlugin(entry.path(), _materialFactory);
                        } catch (const DLLoaderError &e) {
                            throw PluginLoaderError("Error while loading plugin: " + entry.path().string() + "\n" + e.what());
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    } catch (const std::filesystem::filesystem_error &e) {
        throw PluginLoaderError("Error while loading plugins: " + std::string(e.what()));
    }
}

RayTracer::Factory<RayTracer::IObject> &RayTracer::PluginLoader::getObjectFactory()
{
    return _objectFactory;
}

RayTracer::Factory<RayTracer::ILight> &RayTracer::PluginLoader::getLightFactory()
{
    return _lightFactory;
}

RayTracer::Factory<RayTracer::IMaterial> &RayTracer::PluginLoader::getMaterialFactory()
{
    return _materialFactory;
}
