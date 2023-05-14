/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** Mirror
*/

#include "Mirror.hpp"

RayTracer::Mirror::Mirror()
    : _color(1, 1, 1), _refractionIndex(1)
{
}

RayTracer::Color RayTracer::Mirror::getPointColor(const RayTracer::Ray &ray, const RayTracer::RayHit &hit) const
{
    RayTracer::Color color = getColor();

    return color;
}

bool RayTracer::Mirror::getScatter(const RayTracer::Ray &ray, const RayTracer::RayHit &hit, RayTracer::Scatter &scatter) const
{
    Math::Vector<3> reflected = ray.getDirection() - hit.normal * ray.getDirection().dot(hit.normal) * 2;
    
    double specular = 1.9;

    if (specular > 0) {
        double specularIntensity = pow(reflected.dot((ray.getDirection() * -1.0)), 4) * specular;
        specularIntensity *= 1.0 - hit.normal.dot(ray.getDirection() * -1.0);
        scatter.attenuation = getColor() * (1 - (specular / 6)) + RayTracer::Color(specularIntensity, specularIntensity, specularIntensity) * specular;
    } else {
        scatter.attenuation = getColor();
    }

    scatter.reflected = Ray(hit.point, reflected);
    scatter.reflectionIndex = getRefractionIndex();
    scatter.transmissionIndex = 1.0 - getRefractionIndex();
    return true;
}

RayTracer::Color RayTracer::Mirror::getColor() const noexcept
{
    return _color;
}

void RayTracer::Mirror::setColor(const RayTracer::Color &color) noexcept
{
    _color = color;
}

double RayTracer::Mirror::getRefractionIndex() const noexcept
{
    return _refractionIndex;
}

void RayTracer::Mirror::setRefractionIndex(double refractionIndex) noexcept
{
    _refractionIndex = refractionIndex;
}
