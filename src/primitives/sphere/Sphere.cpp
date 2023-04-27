/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Sphere
*/

#include "Sphere.hpp"

RayTracer::Sphere::Sphere(const Math::Point<3> &center, std::shared_ptr<RayTracer::IMaterial> &material, double radius)
    : AObject(center, material), _center(center), _radius(radius)
{
}

bool RayTracer::Sphere::hits(const RayTracer::Ray &ray, std::unique_ptr<RayHit> &hit) const
{
    Math::Vector<3> oc = ray.getOrigin() - _center;
    auto a = ray.getDirection().lengthSquared();
    auto b = oc.dot(ray.getDirection());
    auto c = oc.lengthSquared() - _radius * _radius;
    auto discriminant = b * b - a * c;

    if (discriminant < 0)
        return false;
    if (discriminant == 0) {
        hit->distance = -b / a;
        hit->point = ray.getPoint(hit->distance);
        hit->normal = Math::Vector<3>(hit->point - _center) / _radius;
    } else {
        auto temp = (-b - sqrt(discriminant)) / a;
        if (temp > 0) {
            hit->distance = temp;
            hit->point = ray.getPoint(hit->distance);
            hit->normal = Math::Vector<3>(hit->point - _center) / _radius;
        } else {
            temp = (-b + sqrt(discriminant)) / a;
            hit->distance = temp;
            hit->point = ray.getPoint(hit->distance);
            hit->normal = Math::Vector<3>(hit->point - _center) / _radius;
        }
    }
    return true;
}

