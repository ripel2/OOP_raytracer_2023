/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** AmbientLight
*/

#include "AmbientLight.hpp"

RayTracer::AmbientLight::AmbientLight(double intensity)
    : _color(0, 0, 0), _intensity(intensity)
{
}

RayTracer::AmbientLight::AmbientLight(const RayTracer::Color &color, double intensity)
    : _color(color), _intensity(intensity)
{
}

RayTracer::Color RayTracer::AmbientLight::applyLight(const RayTracer::Color &pixel, const Ray &ray, const RayHit &hit) const
{
    (void)ray;
    (void)hit;
    return (pixel * _color) * _intensity;
}
