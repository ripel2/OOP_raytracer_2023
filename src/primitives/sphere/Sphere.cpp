/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Sphere
*/

#include "Sphere.hpp"

RayTracer::Sphere::Sphere()
    : _radius(1)
{
}

bool RayTracer::Sphere::hits(const RayTracer::Ray &ray, RayHit &hit) const
{
    Math::Matrix transformation = getTransformation();
    Math::Point<3> trPosition = getPosition();
    trPosition[0] += transformation(0, 3);
    transformation(0, 3) = 0;
    trPosition[1] += transformation(1, 3);
    transformation(1, 3) = 0;
    trPosition[2] += transformation(2, 3);
    transformation(2, 3) = 0;
    Math::Point<3> _center = trPosition;
    Math::Vector<3> oc = ray.getOrigin() - _center;
    auto a = ray.getDirection().lengthSquared();
    auto b = oc.dot(ray.getDirection());
    auto c = oc.lengthSquared() - _radius * _radius;
    auto discriminant = b * b - a * c;

    if (discriminant < 0)
        return false;
    if (discriminant == 0) {
        hit.distance = -b / a;
        hit.point = ray.getPoint(hit.distance);
        hit.normal = Math::Vector<3>(hit.point - _center) / _radius;
    } else {
        auto temp = (-b - sqrt(discriminant)) / a;
        if (temp > 0) {
            hit.distance = temp;
            hit.point = ray.getPoint(hit.distance);
            hit.normal = Math::Vector<3>(hit.point - _center) / _radius;
        } else {
            temp = (-b + sqrt(discriminant)) / a;
            hit.distance = temp;
            hit.point = ray.getPoint(hit.distance);
            hit.normal = Math::Vector<3>(hit.point - _center) / _radius;
        }
    }
    hit.normal.normalize();
    return true;
}

double RayTracer::Sphere::getRadius() const noexcept
{
    return _radius;
}

void RayTracer::Sphere::setRadius(double radius) noexcept
{
    _radius = radius;
}
