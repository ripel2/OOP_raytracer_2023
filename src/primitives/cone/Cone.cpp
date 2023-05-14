/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Cone
*/

#include "Cone.hpp"

RayTracer::Cone::Cone()
    : _radius(1), _height(std::numeric_limits<double>::infinity())
{
}

bool RayTracer::Cone::hits(const RayTracer::Ray &ray, RayHit &hit) const
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

bool RayTracer::Cone::_hitsSide(const RayTracer::Ray &ray, RayHit &hit) const
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
    double height = getHeight();
    Math::Matrix invTransformation = transformation.inverse();
    Math::Vector<3> direction = invTransformation * ray.getDirection();
    Math::Point<3> origin = invTransformation * (ray.getOrigin() - trPosition);
    RayTracer::Ray transformedRay(origin, direction);
    double dm = getRadius() * 2;
    double _k = dm;
    if (std::isfinite(height))
        _k = dm / height;
    _k = _k * _k;
    double a = direction[0] * direction[0] - _k * direction[1] * direction[1] + direction[2] * direction[2];
    double b = 2 * (origin[0] * direction[0] - _k * (origin[1]) * direction[1] + origin[2] * direction[2]);
    double c = origin[0] * origin[0] - _k * (origin[1]) * (origin[1]) + origin[2] * origin[2];
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return false;

    double t1 = (-b - sqrt(discriminant)) / (2 * a);
    double t2 = (-b + sqrt(discriminant)) / (2 * a);

    if (t1 > t2)
        std::swap(t1, t2);

    double y1 = origin[1] + t1 * direction[1];
    double y2 = origin[1] + t2 * direction[1];

    if (std::isfinite(height)) {
        if (y1 < -height / 2.0 || y1 > height / 2.0)
            t1 = -1;

        if (y2 < -height / 2.0 || y2 > height / 2.0)
            t2 = -1;

        if (t1 < 0 && t2 < 0)
            return false;
    }

    double t = (t1 < 0) ? t2 : ((t2 < 0) ? t1 : std::min(t1, t2));

    if (t < 0)
        return false;

    Math::Point<3> point = transformedRay.getPoint(t);
    Math::Point<3> realPoint = transformation * point + trPosition;
    Math::Point<3> pointOnCenterLine = center + Math::Vector<3>({0, point[1] - center[1], 0});
    Math::Vector<3> normal = point - pointOnCenterLine;
    normal.normalize();
    normal = invTransformation.transpose() * normal;
    normal.normalize();

    hit.distance = Math::Vector<3>(realPoint - ray.getOrigin()).length();
    hit.point = realPoint;
    hit.normal = normal;
    return true;
}

bool RayTracer::Cone::_hitsCap(const RayTracer::Ray &ray, RayHit &hit, bool offsetBottom) const
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

double RayTracer::Cone::getRadius() const noexcept
{
    return _radius;
}

void RayTracer::Cone::setRadius(double radius) noexcept
{
    _radius = radius;
}

double RayTracer::Cone::getHeight() const noexcept
{
    return _height;
}

void RayTracer::Cone::setHeight(double height) noexcept
{
    _height = height;
}
