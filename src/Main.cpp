/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** Main
*/

#include "Camera.hpp"
#include "Color.hpp"
#include "Ray.hpp"
#include "RayHit.hpp"
#include "Sphere.hpp"
#include "AmbientLight.hpp"
#include "DirectionalLight.hpp"
#include "Scene.hpp"
#include "PPMRenderer.hpp"
#include "FlatColor.hpp"

std::shared_ptr<RayTracer::IObject> createSphere(const Math::Point<3> &center, double radius, const RayTracer::Color &color)
{
    /* Should be created by the factory*/
    std::shared_ptr<RayTracer::FlatColor> material = std::make_shared<RayTracer::FlatColor>();
    std::shared_ptr<RayTracer::Sphere> sphere = std::make_shared<RayTracer::Sphere>();

    /* Should be called by the builder */
    material->setColor(color);
    sphere->setPosition(center);
    sphere->setMaterial(material);
    sphere->setRadius(radius);
    return sphere;
}

std::shared_ptr<RayTracer::ILight> createAmbientLight(const RayTracer::Color &color, double intensity)
{
    /* Should be created by the factory*/
    std::shared_ptr<RayTracer::AmbientLight> light = std::make_shared<RayTracer::AmbientLight>();

    /* Should be called by the builder */
    light->setColor(color);
    light->setIntensity(intensity);
    return light;
}

std::shared_ptr<RayTracer::ILight> createDirectionalLight(const Math::Vector<3> &direction, const RayTracer::Color &color, double intensity)
{
    /* Should be created by the factory*/
    std::shared_ptr<RayTracer::DirectionalLight> light = std::make_shared<RayTracer::DirectionalLight>();

    /* Should be called by the builder */
    light->setColor(color);
    light->setIntensity(intensity);
    light->setDirection(direction);
    return light;
}

int main(int ac, char **av)
{
    /* Creating objects - should be done with the factory and builder */
    std::shared_ptr<RayTracer::IObject> sphere1 = createSphere(Math::Point<3>({0, 0, 0}), 0.5, RayTracer::Color({1, 0, 0}));
    std::shared_ptr<RayTracer::IObject> sphere2 = createSphere(Math::Point<3>({2, 0, 0}), 0.5, RayTracer::Color({0, 1, 0}));
    std::shared_ptr<RayTracer::IObject> sphere3 = createSphere(Math::Point<3>({-2, 0, 0}), 0.5, RayTracer::Color({0, 0, 1}));

    /* Creating lights - should be done with the factory and builder */
    std::shared_ptr<RayTracer::ILight> ambientLight = createAmbientLight(RayTracer::Color({1, 1, 1}), 0.2);
    std::shared_ptr<RayTracer::ILight> directionalLight = createDirectionalLight(Math::Vector<3>({0, 0.5, 0}), RayTracer::Color({1, 1, 1}), 0.6);

    /* Creating the camera */
    Math::Point<3> cam_origin({0, 0, -2});
    Math::Point<3> cam_lookAt({0, 0, 0});
    Math::Vector<3> cam_up({0, 1, 0});
    std::shared_ptr<RayTracer::Camera> cam = std::make_shared<RayTracer::Camera>(cam_origin, cam_lookAt, cam_up, 50, 16.0 / 9.0);

    /* Creating the scene */
    RayTracer::Scene scene;
    scene.addObject(sphere1);
    scene.addObject(sphere2);
    scene.addObject(sphere3);
    scene.addLight(ambientLight);
    scene.addLight(directionalLight);
    scene.setCamera(cam);

    /* Creating the renderer */
    RayTracer::PPMRenderer renderer("image.ppm");

    /* Rendering the image */
    renderer.render(854, 480, scene);
}
