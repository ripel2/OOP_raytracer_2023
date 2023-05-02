/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** ARenderer
*/

#include "ARenderer.hpp"

RayTracer::ARenderer::ARenderer()
    : _rayHit(), _tmp()
{
}

RayTracer::Color RayTracer::ARenderer::getColor(double u, double v, const RayTracer::Scene &scene)
{
    std::shared_ptr<RayTracer::Camera> camera = scene.getCamera();
    RayTracer::Ray ray = camera->getRay(u, v);
    std::shared_ptr<IObject> closest = nullptr;
    
    for (std::shared_ptr<IObject> object : scene.getObjects()) {
        bool hits = object->hits(ray, _tmp);
        if (hits && (!closest || _tmp.distance < _rayHit.distance)) {
            _rayHit = _tmp;
            closest = object;
        }
    }
    if (closest) {
        std::shared_ptr<IMaterial> material = closest->getMaterial();
        RayTracer::Color pixel = material->getPointColor(ray, _rayHit);
        RayTracer::Color finalColor;
        for (std::shared_ptr<ILight> light : scene.getLights()) {
            finalColor += light->applyLight(pixel, ray, _rayHit, scene.getObjects());
        }
        finalColor.clamp();
        return finalColor;
    }
    return RayTracer::Color(0, 0, 0);
}
