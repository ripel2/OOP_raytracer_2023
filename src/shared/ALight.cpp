/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** ALight
*/

#include "ALight.hpp"

RayTracer::ALight::ALight()
    : _intensity(0)
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

RayTracer::Color RayTracer::ALight::getColor() const noexcept
{
    std::cerr << "Warning : Called ALight::getColor() function from abstract" << std::endl;
    return RayTracer::Color();
}

void RayTracer::ALight::setColor(const RayTracer::Color &color) noexcept
{
    std::cerr << "Warning : Called ALight::setColor() function from abstract" << std::endl;
    (void)color;
}

Math::Vector<3> RayTracer::ALight::getDirection() const noexcept
{
    std::cerr << "Warning : Called ALight::getDirection() function from abstract" << std::endl;
    return Math::Vector<3>();
}

void RayTracer::ALight::setDirection(const Math::Vector<3> &direction) noexcept
{
    std::cerr << "Warning : Called ALight::setDirection() function from abstract" << std::endl;
    (void)direction;
}

Math::Point<3> RayTracer::ALight::getPosition() const noexcept
{
    std::cerr << "Warning : Called ALight::getPosition() function from abstract" << std::endl;
    return Math::Point<3>();
}

void RayTracer::ALight::setPosition(const Math::Point<3> &position) noexcept
{
    std::cerr << "Warning : Called ALight::setPosition() function from abstract" << std::endl;
    (void)position;
}
