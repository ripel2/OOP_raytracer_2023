/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** AObject
*/

#include "AObject.hpp"

RayTracer::AObject::AObject()
<<<<<<< HEAD
    : _position(), _material(nullptr)
{
=======
    : _position(), _material(nullptr), _translation(4, 4), _rotation(4, 4), _scale(4, 4)
{
    for (std::size_t c = 0; c < 4; c++) {
        _translation(c, c) = 1;
        _rotation(c, c) = 1;
        _scale(c, c) = 1;
    }
>>>>>>> main
}

const Math::Point<3> &RayTracer::AObject::getPosition() const noexcept
{
    return _position;
}

void RayTracer::AObject::setPosition(const Math::Point<3> &position) noexcept
{
    _position = position;
}

<<<<<<< HEAD
=======
const Math::Matrix &RayTracer::AObject::getTranslation() const noexcept
{
    return _translation;
}

void RayTracer::AObject::setTranslation(const Math::Vector<3> &translation) noexcept
{
    _translation(0, 3) = translation[0];
    _translation(1, 3) = translation[1];
    _translation(2, 3) = translation[2];
}

const Math::Matrix &RayTracer::AObject::getRotation() const noexcept
{
    return _rotation;
}

void RayTracer::AObject::setRotation(const Math::Vector<3> &rotation) noexcept
{
    _rotation(0, 0) = cos(rotation[1]) * cos(rotation[2]);
    _rotation(0, 1) = cos(rotation[2]) * sin(rotation[0]) * sin(rotation[1]) - cos(rotation[0]) * sin(rotation[2]);
    _rotation(0, 2) = cos(rotation[0]) * cos(rotation[2]) * sin(rotation[1]) + sin(rotation[0]) * sin(rotation[2]);
    _rotation(1, 0) = cos(rotation[1]) * sin(rotation[2]);
    _rotation(1, 1) = cos(rotation[0]) * cos(rotation[2]) + sin(rotation[0]) * sin(rotation[1]) * sin(rotation[2]);
    _rotation(1, 2) = -cos(rotation[2]) * sin(rotation[0]) + cos(rotation[0]) * sin(rotation[1]) * sin(rotation[2]);
    _rotation(2, 0) = -sin(rotation[1]);
    _rotation(2, 1) = cos(rotation[1]) * sin(rotation[0]);
    _rotation(2, 2) = cos(rotation[0]) * cos(rotation[1]);
}

const Math::Matrix &RayTracer::AObject::getScale() const noexcept
{
    return _scale;
}

void RayTracer::AObject::setScale(const Math::Vector<3> &scale) noexcept
{
    _scale(0, 0) = scale[0];
    _scale(1, 1) = scale[1];
    _scale(2, 2) = scale[2];
}

>>>>>>> main
Math::Vector<3> RayTracer::AObject::getNormal() const noexcept
{
    std::cerr << "Warning : Called AObject::getNormal() function from abstract" << std::endl;
    return Math::Vector<3>();
}

void RayTracer::AObject::setNormal(const Math::Vector<3> &normal) noexcept
{
    std::cerr << "Warning : Called AObject::setNormal() function from abstract" << std::endl;
    (void)normal;
}

Math::Vector<3> RayTracer::AObject::getDistance() const noexcept
{
    std::cerr << "Warning : Called AObject::getDistance() function from abstract" << std::endl;
    return Math::Vector<3>();
}

void RayTracer::AObject::setDistance(const Math::Vector<3> &distance) noexcept
{
    std::cerr << "Warning : Called AObject::setDistance() function from abstract" << std::endl;
    (void)distance;
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
<<<<<<< HEAD
=======

Math::Matrix RayTracer::AObject::getTransformation() const noexcept
{
    return _translation * _rotation * _scale;
}
>>>>>>> main
