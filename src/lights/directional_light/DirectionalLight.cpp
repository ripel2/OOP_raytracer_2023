/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

RayTracer::DirectionalLight::DirectionalLight()
    : ALight(), _direction(Math::Vector<3>()), _color(RayTracer::Color(1, 1, 1))
{
    setIntensity(1.0);
}

RayTracer::Color RayTracer::DirectionalLight::applyLight(const RayTracer::Color &pixel, const Ray &ray,

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

Math::Vector<3> RayTracer::DirectionalLight::getDirection() const noexcept
{
    return _direction;
}

void RayTracer::DirectionalLight::setDirection(const Math::Vector<3> &direction) noexcept
{
    _direction = direction;
}

RayTracer::Color RayTracer::DirectionalLight::getColor() const noexcept
{
    return _color;
}

void RayTracer::DirectionalLight::setColor(const RayTracer::Color &color) noexcept
{
    _color = color;
}
