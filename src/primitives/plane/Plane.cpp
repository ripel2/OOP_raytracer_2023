/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** Plane
*/

#include "Plane.hpp"

RayTracer::Plane::Plane()
    : _distance({std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}), _normal(Math::Vector<3>({0, 1, 0}))
{
}

bool RayTracer::Plane::hits(const RayTracer::Ray &ray, RayHit &hit) const
{
    Math::Matrix transformation = getTransformation();
    Math::Point<3> center;
    Math::Point<3> trPosition = getPosition();
    trPosition[0] += transformation(0, 3);
    transformation(0, 3) = 0;
    trPosition[1] += transformation(1, 3);
    transformation(1, 3) = 0;
    trPosition[2] += transformation(2, 3);
    transformation(2, 3) = 0;
    Math::Matrix invTransformation = transformation.inverse();
    Math::Vector<3> direction = invTransformation * ray.getDirection();
    Math::Point<3> origin = invTransformation * (ray.getOrigin() - trPosition);
    RayTracer::Ray transformedRay(origin, direction);
    Math::Vector<3> p0l0 = (center - transformedRay.getOrigin());
    Math::Vector<3> normal = invTransformation * Math::Vector<3>({0, 1, 0}) * getNormal();

    if (std::isnan(normal[0]) || std::isnan(normal[1]) || std::isnan(normal[2]))
        return false;

    normal.normalize();

    if (std::isnan(normal[0]) || std::isnan(normal[1]) || std::isnan(normal[2]))
        return false;

    double denom = normal.dot(transformedRay.getDirection());
    double t = normal.dot(p0l0) / denom;

    if (t < 0)
        return false;
    
    Math::Point<3> point = transformedRay.getPoint(t);
    Math::Point<3> realPoint = transformation * point + trPosition;
    
    Math::Vector<3> extent = getDistance() / 2.0;
    Math::Vector<3> transformedExtent = invTransformation * extent;
    Math::Point<3> p0p = point - center;

    if (std::abs(extent[0]) > 0.001 && std::abs(p0p[0]) > transformedExtent[0])
        return false;
    if (std::abs(extent[1]) > 0.001 && std::abs(p0p[1]) > transformedExtent[1])
        return false;
    if (std::abs(extent[2]) > 0.001 && std::abs(p0p[2]) > transformedExtent[2])
        return false;

    hit.distance = Math::Vector<3>(realPoint - ray.getOrigin()).length();
    hit.point = realPoint;
    hit.normal = normal;
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
    _normal = normal.getNormalized();
}
