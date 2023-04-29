/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** AObject
*/

#include "AObject.hpp"

RayTracer::AObject::AObject()
    : _position(), _material(nullptr)
{
}

const Math::Point<3> &RayTracer::AObject::getPosition() const noexcept
{
    return _position;
}

void RayTracer::AObject::setPosition(const Math::Point<3> &position) noexcept
{
    _position = position;
}

const std::shared_ptr<RayTracer::IMaterial> &RayTracer::AObject::getMaterial() const noexcept
{
    return _material;
}

void RayTracer::AObject::setMaterial(const std::shared_ptr<RayTracer::IMaterial> &material) noexcept
{
    _material = material;
}

double RayTracer::AObject::getRadius() const noexcept
{
    std::cerr << "Warning : Called AObject::getRadius() function from abstract" << std::endl;
    return 0;
}

void RayTracer::AObject::setRadius(double radius) noexcept
{
    std::cerr << "Warning : Called AObject::setRadius() function from abstract" << std::endl;
    (void)radius;
}

double RayTracer::AObject::getHeight() const noexcept
{
    std::cerr << "Warning : Called AObject::getHeight() function from abstract" << std::endl;
    return 0;
}

void RayTracer::AObject::setHeight(double height) noexcept
{
    std::cerr << "Warning : Called AObject::setHeight() function from abstract" << std::endl;
    (void)height;
}

double RayTracer::AObject::getInnerRadius() const noexcept
{
    std::cerr << "Warning : Called AObject::getInnerRadius() function from abstract" << std::endl;
    return 0;
}

void RayTracer::AObject::setInnerRadius(double innerRadius) noexcept
{
    std::cerr << "Warning : Called AObject::setInnerRadius() function from abstract" << std::endl;
    (void)innerRadius;
}
