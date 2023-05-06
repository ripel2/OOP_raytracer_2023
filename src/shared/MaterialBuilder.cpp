/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** MaterialBuilder
*/

#include "MaterialBuilder.hpp"

RayTracer::MaterialBuilder::MaterialBuilder(IMaterial *material)
{
    _material = dynamic_cast<AMaterial *>(material);
    if (!_material)
        throw RayTracer::BuilderError("MaterialBuilder: invalid material (cannot cast to AMaterial *)");
}

void RayTracer::MaterialBuilder::set(const std::string &name, const double &value)
{
    if (name == "refraction" || name == "refractionIndex")
        _material->setRefractionIndex(value);
    else if (name == "albedo")
        _material->setAlbedo(value);
    else if (name == "fuzz" || name == "fuzziness")
        _material->setFuzziness(value);
    else
        throw RayTracer::BuilderError("MaterialBuilder: " + name + " is not a valid setter or doesn't take a double");
}

void RayTracer::MaterialBuilder::set(const std::string &name, const Color &value)
{
    if (name == "color")
        _material->setColor(value);
    else
        throw RayTracer::BuilderError("MaterialBuilder: " + name + " is not a valid setter or doesn't take a Color");
}

void RayTracer::MaterialBuilder::set(const std::string &name, const Math::Vector<3> &value)
{
    throw RayTracer::BuilderError("MaterialBuilder: " + name + " is not a valid setter or doesn't take a Vector");
}

void RayTracer::MaterialBuilder::set(const std::string &name, const Math::Point<3> &value)
{
    throw RayTracer::BuilderError("MaterialBuilder: " + name + " is not a valid setter or doesn't take a Point");
}
