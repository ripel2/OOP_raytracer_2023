/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** AmbientLight
*/

#include "AmbientLight.hpp"

RayTracer::AmbientLight::AmbientLight()
    : ALight(), _color(RayTracer::Color(1, 1, 1))
{
    setIntensity(1.0);
}

RayTracer::Color RayTracer::AmbientLight::applyLight(const RayTracer::Color &pixel, const Ray &ray,
const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const
{
    (void)ray;
    (void)hit;
    (void)objects;
    return (pixel * _color) * getIntensity();
}

RayTracer::Color RayTracer::AmbientLight::getColor() const noexcept
{
    return _color;
}

void RayTracer::AmbientLight::setColor(const RayTracer::Color &color) noexcept
{
    _color = color;
}
