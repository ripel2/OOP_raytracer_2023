/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** ARenderer
*/

#include "ARenderer.hpp"

RayTracer::Color RayTracer::ARenderer::getColor(double u, double v, const RayTracer::Scene &scene)
{
    std::shared_ptr<RayTracer::Camera> camera = scene.getCamera();
    RayTracer::Ray ray = camera->getRay(u, v);
    std::shared_ptr<IObject> closest = nullptr;
    RayHit tmp;
    RayHit rayHit;

    tmp.distance = std::numeric_limits<double>::max();
    rayHit.distance = std::numeric_limits<double>::max();
    for (std::shared_ptr<IObject> object : scene.getObjects()) {
        bool hits = object->hits(ray, tmp);
        if (hits && (closest == nullptr || tmp.distance < rayHit.distance)) {
            rayHit = tmp;
            rayHit.object = object;
            closest = object;
        }
    }
    if (closest) {
        std::shared_ptr<IMaterial> material = closest->getMaterial();
        RayTracer::Color pixel = material->getPointColor(ray, rayHit);
        RayTracer::Color finalColor;
        for (std::shared_ptr<ILight> light : scene.getLights()) {
            finalColor += light->applyLight(pixel, ray, rayHit, scene.getObjects());
        }
        finalColor.clamp();
        return finalColor;
    }
    return RayTracer::Color(0, 0, 0);
}
