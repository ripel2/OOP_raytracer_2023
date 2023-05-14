/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** PhongLight
*/

#include "PhongLight.hpp"

RayTracer::PhongLight::PhongLight()
    : _color(1, 1, 1)
{
}

RayTracer::Color RayTracer::PhongLight::applyLight(const Color &pixel, const Ray &ray,
    const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const
{
    RayTracer::Color finalColor = _applyAmbientLight(pixel, ray, hit, objects);

    finalColor += _applyDiffuseLight(pixel, ray, hit, objects);
    return finalColor;
}

RayTracer::Color RayTracer::PhongLight::_applyAmbientLight(const Color &pixel, const Ray &ray,
    const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const
{
    return (pixel * _color) * getIntensity();
}

RayTracer::Color RayTracer::PhongLight::_applyDiffuseLight(const Color &pixel, const Ray &ray,
    const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const
{
    Math::Vector<3> lightDir = _direction;

    double dot = hit.normal.dot(lightDir);
    (void)ray;
    (void)objects;
    if (dot > 0) {
        return (pixel * _color) * getIntensity() * dot;
    }
    return Math::Vector<3>();
}

RayTracer::Color RayTracer::PhongLight::_applySpecularLight(const Color &pixel, const Ray &ray,
    const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const
{
    (void)pixel;
    (void)ray;
    (void)hit;
    (void)objects;
    return Math::Vector<3>();
}
