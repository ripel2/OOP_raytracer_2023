/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** ALight
*/

#include "ALight.hpp"

RayTracer::ALight::ALight()
    : _intensity(0), _color()
{
}

double RayTracer::ALight::getIntensity() const noexcept
{
    return _intensity;
}

void RayTracer::ALight::setIntensity(double intensity)
{
    if (intensity < 0 || intensity > 1)
        throw std::invalid_argument("ALight intensity must be between 0 and 1");
    _intensity = intensity;
}

const RayTracer::Color &RayTracer::ALight::getColor() const noexcept
{
    return _color;
}

void RayTracer::ALight::setColor(const RayTracer::Color &color) noexcept
{
    _color = color;
}
