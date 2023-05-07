/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** Scene
*/

#include "Scene.hpp"

RayTracer::Scene::Scene()
{
}

RayTracer::Scene::~Scene()
{
    for (auto &object : _objects)
        delete object;
    for (auto &light : _lights)
        delete light;
    delete _camera;
}

void RayTracer::Scene::addObject(std::unique_ptr<RayTracer::IObject> &object)
{
    _objects.push_back(object.release());
}

void RayTracer::Scene::addLight(std::unique_ptr<RayTracer::ILight> &light)
{
    _lights.push_back(light.release());
}

void RayTracer::Scene::setCamera(std::unique_ptr<RayTracer::Camera> &camera)
{
    _camera = camera.release();
}

const std::vector<RayTracer::IObject *> &RayTracer::Scene::getObjects() const
{
    return _objects;
}

const std::vector<RayTracer::ILight *> &RayTracer::Scene::getLights() const
{
    return _lights;
}

const RayTracer::Camera *RayTracer::Scene::getCamera() const
{
    return _camera;
}
