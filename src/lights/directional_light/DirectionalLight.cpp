/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

RayTracer::DirectionalLight::DirectionalLight(const Math::Vector<3> &direction, double intensity)
    : _direction(direction), _color(Math::Vector<3>()), _intensity(intensity)
{
}

RayTracer::DirectionalLight::DirectionalLight(const Math::Vector<3> &direction, const RayTracer::Color &color, double intensity)
    : _direction(direction), _color(color), _intensity(intensity)
{
}

RayTracer::Color RayTracer::DirectionalLight::applyLight(const RayTracer::Color &pixel, const Ray &ray, const RayHit &hit) const
{
    Math::Vector<3> lightResult = Math::Vector<3>();
    Math::Vector<3> lightDir = _direction * -1;

    (void)ray;
    if (hit.normal.dot(lightDir) > 0) {
        lightResult = (pixel * _color) * _intensity * hit.normal.dot(lightDir);
    }
    return lightResult;
}
