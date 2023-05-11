/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** PointLight
*/

#include "PointLight.hpp"

RayTracer::PointLight::PointLight()
    : _position(), _color(1, 1, 1), _shadowRayCount(0), _shadowRayOffset(0.0), _seed(std::make_unique<unsigned int>(time(nullptr))), _shadowRayBias(0.9999)
{
}

RayTracer::Color RayTracer::PointLight::applyLight(const Color &pixel, const Ray &ray,
const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const
{
    std::vector<RayTracer::Color> colors;

    if (_shadowRayCount == 0 || _shadowRayOffset <= 0.0) {
        return _applyLightMain(pixel, ray, hit, objects);
    }
    if (_shadowRayCount > 1 && _shadowRayOffset > 0.0) {
        for (std::size_t i = 0; i < _shadowRayCount; i++) {
            double x = (rand_r(_seed.get()) % 100) / 100.0;
            double y = (rand_r(_seed.get()) % 100) / 100.0;
            double z = (rand_r(_seed.get()) % 100) / 100.0;
            x *= getShadowRayOffset();
            y *= getShadowRayOffset();
            z *= getShadowRayOffset();
            colors.push_back(_applyLightOffset(pixel, ray, hit, objects, Math::Point<3>({x, y, z})));
        }
    }
    RayTracer::Color finalColor = colors[0];
    for (int i = 1; i < colors.size(); i++) {
        finalColor += colors[i];
    }
    finalColor /= colors.size();
    return finalColor;
}

RayTracer::Color RayTracer::PointLight::_applyLightMain(const Color &pixel, const Ray &ray,
const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const
{
    return _applyLightOffset(pixel, ray, hit, objects, Math::Point<3>({0, 0, 0}));
}

RayTracer::Color RayTracer::PointLight::_applyLightOffset(const Color &pixel, const Ray &ray,
const RayHit &hit, const std::vector<RayTracer::IObject *> &objects, const Math::Point<3> &offset) const
{
    Math::Point<3> position = getPosition() + offset;
    Math::Vector<3> shadowDir = hit.point - position;
    Math::Vector<3> lightDir = position - hit.point;
    Ray shadowRay(position, shadowDir.getNormalized());

    for (auto &object : objects) {
        RayHit shadowHit;
        if (object == hit.object)
            continue;
        if (object->hits(shadowRay, shadowHit) && shadowHit.distance > 0.0 && shadowHit.distance < shadowDir.length() * getShadowRayBias()) {
            return RayTracer::Color();
        }
    }
    double dot = hit.normal.dot(lightDir);
    if (dot > 0) {
        double distance = lightDir.length();
        double attenuation = 1.0 / (distance * 2);
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

double RayTracer::PointLight::getShadowRayOffset() const noexcept
{
    return _shadowRayOffset;
}

void RayTracer::PointLight::setShadowRayOffset(double offset) noexcept
{
    _shadowRayOffset = offset;
}

int RayTracer::PointLight::getShadowRayCount() const noexcept
{
    return _shadowRayCount;
}

void RayTracer::PointLight::setShadowRayCount(int count) noexcept
{
    _shadowRayCount = count;
}

double RayTracer::PointLight::getShadowRayBias() const noexcept
{
    return _shadowRayBias;
}

void RayTracer::PointLight::setShadowRayBias(double bias) noexcept
{
    _shadowRayBias = bias;
}
