/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** PointLight
*/

#include "PointLight.hpp"

RayTracer::PointLight::PointLight()
    : _position(), _color(255, 255, 255)
{
}

RayTracer::Color RayTracer::PointLight::applyLight(const Color &pixel, const Ray &ray,
const RayHit &hit, const std::vector<std::shared_ptr<RayTracer::IObject>> &objects) const
{
    Math::Vector<3> lightDir = getPosition() - hit.point;
    RayTracer::Ray lightRay(getPosition(), lightDir);
    RayHit lightHit;

    for (auto &object : objects) {
        if (object == hit.object)
            continue;
        if (object->hits(lightRay, lightHit)) {
            return RayTracer::Color();
        }
    }
    double dot = hit.normal.dot(lightDir);
    if (dot > 0) {
        double distance = lightDir.length();
        double attenuation = 1.0 / (distance * distance);
        return (pixel * getColor()) * getIntensity() * attenuation * dot;
    }
    return RayTracer::Color();
}

Math::Point<3> RayTracer::PointLight::getPosition() const noexcept
{
    return _position;
}

void RayTracer::PointLight::setPosition(const Math::Point<3> &position) noexcept
{
    _position = position;
}

RayTracer::Color RayTracer::PointLight::getColor() const noexcept
{
    return _color;
}

void RayTracer::PointLight::setColor(const RayTracer::Color &color) noexcept
{
    _color = color;
}
