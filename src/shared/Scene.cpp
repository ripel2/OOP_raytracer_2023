/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** Scene
*/

#include "Scene.hpp"

void RayTracer::Scene::addObject(const std::shared_ptr<RayTracer::IObject> &object)
{
    _objects.push_back(object);
}

void RayTracer::Scene::addLight(const std::shared_ptr<RayTracer::ILight> &light)
{
    _lights.push_back(light);
}

void RayTracer::Scene::setCamera(const std::shared_ptr<RayTracer::Camera> &camera)
{
    _camera = camera;
}

const std::vector<std::shared_ptr<RayTracer::IObject>> &RayTracer::Scene::getObjects() const
{
    return _objects;
}

const std::vector<std::shared_ptr<RayTracer::ILight>> &RayTracer::Scene::getLights() const
{
    return _lights;
}

const std::shared_ptr<RayTracer::Camera> &RayTracer::Scene::getCamera() const
{
    return _camera;
}
