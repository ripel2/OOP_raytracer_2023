/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** ARenderer
*/

#include "ARenderer.hpp"

#include <limits>

static const Math::Vector<3> randomUnitSphereVectorLookup[] = {
    Math::Vector<3>({-0.07361745988183643, 0.4547468128059411, -0.27881948457975314}),
    Math::Vector<3>({-0.2942316497829487, -0.48235020733447387, -0.6813933414477196}),
    Math::Vector<3>({-0.3800811029280422, -0.05328847440347917, 0.7226158913903353}),
    Math::Vector<3>({-0.5272408366988199, -0.6526639312864426, -0.1444468017895093}),
    Math::Vector<3>({0.0506249344589933, 0.6725514423771426, -0.14720369642534004}),
    Math::Vector<3>({-0.05069691077190219, -0.43281963209217666, -0.1899514204286108}),
    Math::Vector<3>({-0.44525704272154276, 0.24184652027894127, -0.35214770429728537}),
    Math::Vector<3>({0.18666769816684048, 0.2399609003185985, -0.19170477478199688}),
    Math::Vector<3>({-0.20977409672668657, -0.478909162673987, -0.08988708853021343}),
    Math::Vector<3>({0.06594924382395972, -0.2462405086353774, -0.541620467700588}),
    Math::Vector<3>({0.18933600761162306, 0.7201678802511169, -0.3212475205032739}),
    Math::Vector<3>({0.4751303712952939, -0.04385155370629712, 0.621926235078976}),
    Math::Vector<3>({0.043913107630051185, 0.19587827934992763, -0.8102495945970078}),
    Math::Vector<3>({-0.4180318004923895, -0.864488709658704, 0.1904785251467429}),
    Math::Vector<3>({0.6492931024234609, 0.4888530675937426, 0.03274384214996395}),
    Math::Vector<3>({-0.2224127449201474, 0.794386965648765, 0.5068134590449767}),
    Math::Vector<3>({-0.41653888712052733, 0.4638473094320352, -0.11655836907201511}),
    Math::Vector<3>({0.1072124871861011, 0.4236687367079284, -0.26003174732110534}),
    Math::Vector<3>({0.09884278701916482, 0.5449759471507694, 0.22761818604726658}),
    Math::Vector<3>({-0.5246703847097947, -0.020897050350854318, -0.2607573499132927}),
    Math::Vector<3>({-0.45234650283996625, 0.5574302294977416, -0.602709163707974}),
    Math::Vector<3>({-0.1279072552376328, 0.6139267545558689, 0.1731144207252331}),
    Math::Vector<3>({0.236700893070388, 0.7570930360881474, 0.052379012211306586}),
    Math::Vector<3>({-0.3248101038684992, -0.21451924947970502, 0.2953501464401804}),
    Math::Vector<3>({-0.7442471001123567, 0.07847324226726804, 0.2733732807737781}),
    Math::Vector<3>({0.692192221977141, 0.19383194375565393, -0.5434708984701595}),
    Math::Vector<3>({0.11891445846669169, 0.4411277060584109, 0.7157922270739525}),
    Math::Vector<3>({-0.05991223921200972, 0.9392989977470441, -0.33519808216576763}),
    Math::Vector<3>({-0.26555994450034404, 0.7469002971211229, -0.043246202806859646}),
    Math::Vector<3>({-0.4842521255218233, -0.2399375896936553, -0.660041928404967}),
    Math::Vector<3>({-0.0044319571150528425, -0.6093712822457131, 0.03064039369357663}),
    Math::Vector<3>({-0.6307456772438909, -0.2191850899760368, 0.1545133329751891}),
    Math::Vector<3>({0.15969992822912138, 0.1589340523565046, 0.5059294560828085}),
    Math::Vector<3>({-0.5654336757223362, -0.006224928824766218, 0.8034932528099927}),
    Math::Vector<3>({0.7592242451510371, 0.047229277027392325, 0.2320983746119587}),
    Math::Vector<3>({0.3047822281671384, -0.46563702119341754, -0.24954647888815273}),
    Math::Vector<3>({-0.4286673240440262, -0.33921555541596127, -0.5559788633562419}),
    Math::Vector<3>({-0.1745709885067379, 0.4683087503326404, -0.12962020098667137}),
    Math::Vector<3>({0.3249737088686351, 0.29740255902806956, -0.49100644430345675}),
    Math::Vector<3>({0.017730191487246083, -0.17487102077714511, 0.7858331484535523}),
    Math::Vector<3>({0.6426396605587033, -0.3013086094846915, -0.2102303031921613}),
    Math::Vector<3>({-0.3853621751007512, 0.0727613574934951, 0.11841740544433788}),
    Math::Vector<3>({-0.2784929073406035, 0.24743694981744557, 0.7072537655184501}),
    Math::Vector<3>({-0.10252777550858605, -0.25585758704065253, -0.01942000184953252}),
    Math::Vector<3>({0.29539264107774965, -0.6703907695698941, 0.5750358487940725}),
    Math::Vector<3>({0.26564009885796214, 0.525888214969646, 0.787474241155623}),
    Math::Vector<3>({0.3688851474205179, -0.1634125809746061, -0.49299221495239687}),
    Math::Vector<3>({0.31353581326116475, -0.5130307740367095, 0.6502746091983647}),
    Math::Vector<3>({0.16812741177839996, -0.17567113428222259, 0.8619831899044892}),
    Math::Vector<3>({-0.10633303907721015, 0.5288362287211958, -0.7281476198852217}),
};

RayTracer::ARenderer::ARenderer()
    : _seed(static_cast<std::size_t>(time(nullptr)))
{
}

RayTracer::Color RayTracer::ARenderer::getColor(double u, double v, const RayTracer::Scene &scene, std::size_t depth)
{
    const RayTracer::Camera *camera = scene.getCamera();
    RayTracer::Ray ray = camera->getRay(u, v);

    return getColor(ray, scene, depth);
}

RayTracer::Color RayTracer::ARenderer::getColor(const RayTracer::Ray &ray, const RayTracer::Scene &scene, std::size_t depth, IObject *lastObject)
{
    IObject *closest = nullptr;
    RayHit tmp;
    RayHit rayHit;

    tmp.distance = std::numeric_limits<double>::max();
    rayHit.distance = std::numeric_limits<double>::max();
    for (IObject *object : scene.getObjects()) {
        if (object == lastObject)
            continue;
        bool hits = object->hits(ray, tmp);
        if (hits && tmp.distance > 0 && (closest == nullptr || tmp.distance < rayHit.distance)) {
            rayHit = tmp;
            rayHit.object = object;
            closest = object;
        }
    }
    if (closest) {
        std::shared_ptr<IMaterial> material = closest->getMaterial();
        Scatter scatter;
        RayTracer::Color pixel;

        if (depth > 0 && material->getScatter(ray, rayHit, scatter)) {
            RayTracer::Color reflectedColor;
            for (std::size_t i = 0; i < 3; i++) {
                Math::Point<3> reflectedOrigin = scatter.reflected.getOrigin() + scatter.reflected.getDirection() * 0.001;
                reflectedOrigin += randomInUnitSphere() * 0.1;
                RayTracer::Ray reflectedRay(reflectedOrigin, scatter.reflected.getDirection());
                reflectedColor += getColor(scatter.reflected, scene, depth - 1, closest) * scatter.reflectionIndex;
            }
            reflectedColor /= 3;
            reflectedColor.clamp();
            pixel = material->getPointColor(ray, rayHit) * scatter.attenuation * (1 - scatter.reflectionIndex);
            pixel += reflectedColor * scatter.reflectionIndex * scatter.attenuation;
            pixel.clamp();
        } else {
            pixel = material->getPointColor(ray, rayHit);
        }
        pixel.clamp();

        RayTracer::Color finalColor;
        for (ILight *light : scene.getLights()) {
            finalColor += light->applyLight(pixel, ray, rayHit, scene.getObjects());
        }
        finalColor.clamp();
        return finalColor;
    }
    return RayTracer::Color(0, 0, 0);
}

Math::Vector<3> RayTracer::ARenderer::randomInUnitSphere()
{
    std::size_t index = _seed % 20;

    _seed <<= 1;
    _seed ^= _seed >> 31;
    _seed ^= _seed >> 11;
    _seed ^= _seed >> 7;
    _seed &= 0x7fffffff;
    return randomUnitSphereVectorLookup[index];
}
