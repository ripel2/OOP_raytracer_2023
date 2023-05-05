/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Ray
*/

#include "Ray.hpp"

RayTracer::Ray::Ray()
    : _origin(Math::Point<3>()), _direction(Math::Vector<3>())
{
}

RayTracer::Ray::Ray(const Math::Point<3> &origin, const Math::Vector<3> &direction)
    : _origin(origin), _direction(direction)
{
}

RayTracer::Ray::Ray(const RayTracer::Ray &ray)
    : _origin(ray._origin), _direction(ray._direction)
{
}

RayTracer::Ray::Ray(RayTracer::Ray &&ray)
    : _origin(std::move(ray._origin)), _direction(std::move(ray._direction))
{
}

RayTracer::Ray &RayTracer::Ray::operator=(const RayTracer::Ray &ray)
{
    _origin = ray._origin;
    _direction = ray._direction;
    return *this;
}

RayTracer::Ray &RayTracer::Ray::operator=(RayTracer::Ray &&ray)
{
    _origin = std::move(ray._origin);
    _direction = std::move(ray._direction);
    return *this;
}

const Math::Point<3> &RayTracer::Ray::getOrigin() const noexcept
{
    return _origin;
}

const Math::Vector<3> &RayTracer::Ray::getDirection() const noexcept
{
    return _direction;
}

Math::Point<3> RayTracer::Ray::getPoint(double distance) const
{
    return _origin + _direction * distance;
}
