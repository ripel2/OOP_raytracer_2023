/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** LightBuilder
*/

#include "LightBuilder.hpp"

RayTracer::LightBuilder::LightBuilder(ILight *light)
{
    _light = dynamic_cast<ALight *>(light);
    if (!_light)
        throw RayTracer::BuilderError("LightBuilder: invalid light (cannot cast to ALight *)");
}

void RayTracer::LightBuilder::set(const std::string &name, const double &value)
{
    if (name == "intensity")
        _light->setIntensity(value);
    else
        throw RayTracer::BuilderError("LightBuilder: " + name + " is not a valid setter or doesn't take a double");
}

void RayTracer::LightBuilder::set(const std::string &name, const Color &value)
{
    if (name == "color")
        _light->setColor(value);
    else
        throw RayTracer::BuilderError("LightBuilder: " + name + " is not a valid setter or doesn't take a Color");
}

void RayTracer::LightBuilder::set(const std::string &name, const Math::Vector<3> &value)
{
    if (name == "direction")
        _light->setDirection(value);
    else
        throw RayTracer::BuilderError("LightBuilder: " + name + " is not a valid setter or doesn't take a Vector<3>");
}

void RayTracer::LightBuilder::set(const std::string &name, const Math::Point<3> &value)
{
    if (name == "position")
        _light->setPosition(value);
    else
        throw RayTracer::BuilderError("LightBuilder: " + name + " is not a valid setter or doesn't take a Point<3>");
}
