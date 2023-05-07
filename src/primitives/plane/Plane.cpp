/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** Plane
*/

#include "Plane.hpp"

RayTracer::Plane::Plane()
    : _distance({1000000.0, 1000000.0, 1000000.0}), _normal(Math::Vector<3>({0, 1, 0}))
{
}

bool RayTracer::Plane::hits(const RayTracer::Ray &ray, RayHit &hit) const
{
    double denominator = ray.getDirection().dot(_normal);
    Math::Vector<3> p0l0 = (getPosition() - ray.getOrigin());
    double numerator = p0l0.dot(getNormal());

    if (denominator == 0)
        return false;
    double t = numerator / denominator;
    if (t < 0)
        return false;
    Math::Point<3> point = ray.getOrigin() + ray.getDirection() * t;
    Math::Vector<3> extent = getDistance() / 2.0;
    Math::Vector<3> p0p = point - getPosition();
    if (std::abs(extent[0]) > 0.001 && std::abs(p0p[0]) > extent[0])
        return false;
    if (std::abs(extent[1]) > 0.001 && std::abs(p0p[1]) > extent[1])
        return false;
    if (std::abs(extent[2]) > 0.001 && std::abs(p0p[2]) > extent[2])
        return false;
    hit.distance = t;
    hit.point = point;
    hit.normal = getNormal();
    return true;
}

Math::Vector<3> RayTracer::Plane::getDistance() const noexcept
{
    return _distance;
}

void RayTracer::Plane::setDistance(const Math::Vector<3> &distance) noexcept
{
    _distance = distance;
}

Math::Vector<3> RayTracer::Plane::getNormal() const noexcept
{
    return _normal;
}

void RayTracer::Plane::setNormal(const Math::Vector<3> &normal) noexcept
{
    _normal = normal;
}
