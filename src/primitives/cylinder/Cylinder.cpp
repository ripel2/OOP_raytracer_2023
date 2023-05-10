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
    if (std::isfinite(getHeight()) && _hitsBottom(ray, bottomHit)) {
        if (!hitted || bottomHit.distance < hit.distance) {
            hit = bottomHit;
            hitted = true;
        }
    }
    if (std::isfinite(getHeight()) && _hitsTop(ray, topHit)) {
        if (!hitted || topHit.distance < hit.distance) {
            hit = topHit;
            hitted = true;
        }
    }
    return hitted;
}

bool RayTracer::Cylinder::_hitsSide(const RayTracer::Ray &ray, RayHit &hit) const
{
    Math::Point<3> center = getPosition();
    Math::Vector<3> direction = ray.getDirection();
    double a = direction[0] * direction[0] + direction[2] * direction[2];
    double b = 2 * (direction[0] * (ray.getOrigin()[0] - center[0]) + direction[2] * (ray.getOrigin()[2] - center[2]));
    double c = (ray.getOrigin()[0] - center[0]) * (ray.getOrigin()[0] - center[0]) + (ray.getOrigin()[2] - center[2]) * (ray.getOrigin()[2] - center[2]) - _radius * _radius;
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0)
        return false;
    
    double t1 = (-b - sqrt(discriminant)) / (2 * a);
    double t2 = (-b + sqrt(discriminant)) / (2 * a);

    if (t1 > t2)
        std::swap(t1, t2);
    
    double y1 = ray.getOrigin()[1] + t1 * direction[1];
    double y2 = ray.getOrigin()[1] + t2 * direction[1];

    double minY = -getHeight() / 2.0;
    double maxY = getHeight() / 2.0;

    if (y1 < minY && y2 < minY)
        return false;
    
    if (y1 > maxY && y2 > maxY)
        return false;
    
    double t = (y1 >= minY && y1 <= maxY) ? t1 : t2;
    
    Math::Point<3> point = ray.getPoint(t);
    Math::Vector<3> normal({point[0] - center[0], 0, point[2] - center[2]});
    normal.normalize();
    
    if (normal.dot(direction) > 0.0)
        normal = Math::Vector<3>({normal[0] * -1, normal[1] * -1, normal[2] * -1});
    
    hit.distance = t;
    hit.point = point;
    hit.normal = normal;
    return true;
}

bool RayTracer::Cylinder::_hitsBottom(const RayTracer::Ray &ray, RayHit &hit) const
{
    Math::Point<3> center = getPosition();
    center[1] -= getHeight() / 2.0;
    Math::Vector<3> p0l0 = (center - ray.getOrigin());
    Math::Vector<3> normal({0, -1, 0});
    double denom = normal.dot(ray.getDirection());
    double t = normal.dot(p0l0) / denom;

    if (t < 0)
        return false;
    
    Math::Point<3> point = ray.getPoint(t);
    double distance = Math::Vector<3>(point - center).length();
    
    if (distance > _radius)
        return false;
    
    hit.distance = t;
    hit.point = point;
    hit.normal = normal;
    return true;
}

bool RayTracer::Cylinder::_hitsTop(const RayTracer::Ray &ray, RayHit &hit) const
{
    Math::Point<3> center = getPosition();
    center[1] += getHeight() / 2.0;
    Math::Vector<3> p0l0 = (center - ray.getOrigin());
    Math::Vector<3> normal({0, 1, 0});
    double denom = normal.dot(ray.getDirection());
    double t = normal.dot(p0l0) / denom;

    if (t < 0)
        return false;
    
    Math::Point<3> point = ray.getPoint(t);
    double distance = Math::Vector<3>(point - center).length();
    
    if (distance > _radius)
        return false;
    
    hit.distance = t;
    hit.point = point;
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
