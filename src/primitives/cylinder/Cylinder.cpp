/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

RayTracer::Cylinder::Cylinder()
    : _radius(1), _height(std::numeric_limits<double>::infinity())
{
}

bool RayTracer::Cylinder::hits(const RayTracer::Ray &ray, RayHit &hit) const
{
    RayHit sideHit;
    RayHit bottomHit;
    RayHit topHit;
    bool hitted = false;

    if (_hitsSide(ray, sideHit)) {
        hit = sideHit;
        hitted = true;
    }
    if (std::isfinite(getHeight()) && _hitsCap(ray, bottomHit, true)) {
        if (!hitted || bottomHit.distance < hit.distance) {
            hit = bottomHit;
            hitted = true;
        }
    }
    if (std::isfinite(getHeight()) && _hitsCap(ray, topHit, false)) {
        if (!hitted || topHit.distance < hit.distance) {
            hit = topHit;
            hitted = true;
        }
    }
    return hitted;
}

bool RayTracer::Cylinder::_hitsSide(const RayTracer::Ray &ray, RayHit &hit) const
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
    double a = direction[0] * direction[0] + direction[2] * direction[2];
    double b = 2 * (direction[0] * (origin[0] - center[0]) + direction[2] * (origin[2] - center[2]));
    double c = (origin[0] - center[0]) * (origin[0] - center[0]) + (origin[2] - center[2]) * (origin[2] - center[2]) - _radius * _radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return false;

    double t1 = (-b - sqrt(discriminant)) / (2 * a);
    double t2 = (-b + sqrt(discriminant)) / (2 * a);

    if (t1 > t2)
        std::swap(t1, t2);

    double y1 = origin[1] + t1 * direction[1];
    double y2 = origin[1] + t2 * direction[1];

    double minY = -getHeight() / 2.0;
    double maxY = getHeight() / 2.0;

    if (y1 < minY && y2 < minY)
        return false;

    if (y1 > maxY && y2 > maxY)
        return false;

    double t = (y1 >= minY && y1 <= maxY) ? t1 : t2;

    if (t < 0)
        return false;
    
    Math::Point<3> point = transformedRay.getPoint(t);
    Math::Point<3> realPoint = transformation * point + trPosition;
    Math::Point<3> pointOnCenterLine = center + Math::Vector<3>({0, point[1] - center[1], 0});
    Math::Vector<3> normal = point - pointOnCenterLine;
    normal.normalize();
    if (normal.dot(transformedRay.getDirection()) > 0)
        normal = normal * -1;
    normal = invTransformation.transpose() * normal;
    normal.normalize();
    hit.distance = Math::Vector<3>(realPoint  - ray.getOrigin()).length();
    hit.point = realPoint;
    hit.normal = normal;
    return true;
}

bool RayTracer::Cylinder::_hitsCap(const RayTracer::Ray &ray, RayHit &hit, bool offsetBottom) const
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
    if (offsetBottom)
        center[1] -= getHeight() / 2.0;
    else
        center[1] += getHeight() / 2.0;
    Math::Vector<3> p0l0 = (center - transformedRay.getOrigin());
    Math::Vector<3> normal;
    if (offsetBottom)
        normal[1] = -1;
    else
        normal[1] = 1;
    double denom = normal.dot(transformedRay.getDirection());
    double t = normal.dot(p0l0) / denom;

    if (t < 0)
        return false;
    
    Math::Point<3> point = transformedRay.getPoint(t);
    Math::Point<3> realPoint = transformation * point + trPosition;
    double distance = Math::Vector<3>(point - center).length();

    if (distance > _radius)
        return false;

    hit.distance = Math::Vector<3>(realPoint  - ray.getOrigin()).length();
    hit.point = realPoint;
    hit.normal = normal;
    return true;
}

double RayTracer::Cylinder::getRadius() const noexcept
{
    return _radius;
}

void RayTracer::Cylinder::setRadius(double radius) noexcept
{
    _radius = radius;
}

double RayTracer::Cylinder::getHeight() const noexcept
{
    return _height;
}

void RayTracer::Cylinder::setHeight(double height) noexcept
{
    _height = height;
}
