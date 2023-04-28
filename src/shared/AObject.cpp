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
