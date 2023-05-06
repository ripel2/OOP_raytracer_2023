/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** ObjectBuilder
*/

#include "ObjectBuilder.hpp"

RayTracer::ObjectBuilder::ObjectBuilder(IObject *object)
{
    _object = dynamic_cast<AObject *>(object);
    if (!_object)
        throw RayTracer::BuilderError("ObjectBuilder: invalid object (cannot cast to AObject *)");
}

void RayTracer::ObjectBuilder::set(const std::string &name, const double &value)
{
    if (name == "radius")
        _object->setRadius(value);
    else if (name == "height")
        _object->setHeight(value);
    else if (name == "inner_radius" || name == "innerRadius")
        _object->setInnerRadius(value); 
    else
        throw RayTracer::BuilderError("ObjectBuilder: " + name + " is not a valid setter or doesn't take a double");
}

void RayTracer::ObjectBuilder::set(const std::string &name, const Color &value)
{
    throw RayTracer::BuilderError("ObjectBuilder: " + name + " is not a valid setter or doesn't take a Color");
}

void RayTracer::ObjectBuilder::set(const std::string &name, const Math::Vector<3> &value)
{
    if (name == "rotation")
        _object->setRotation(value);
    else if (name == "scale")
        _object->setScale(value);
    else if (name == "normal")
        _object->setNormal(value);
    else if (name == "translation")
        _object->setTranslation(value);
    else if (name == "distance")
        _object->setDistance(value);
    else
        throw RayTracer::BuilderError("ObjectBuilder: " + name + " is not a valid setter or doesn't take a Vector<3>");
}

void RayTracer::ObjectBuilder::set(const std::string &name, const Math::Point<3> &value)
{
    if (name == "position")
        _object->setPosition(value);
    else
        throw RayTracer::BuilderError("ObjectBuilder: " + name + " is not a valid setter or doesn't take a Point<3>");
}

void RayTracer::ObjectBuilder::set(const std::string &name, const std::shared_ptr<IMaterial> &value)
{
    if (name == "material")
        _object->setMaterial(value);
    else
        throw RayTracer::BuilderError("ObjectBuilder: " + name + " is not a valid setter or doesn't take a Material");
}
