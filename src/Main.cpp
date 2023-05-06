/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** Main
*/

#include "PluginLoader.hpp"

#include "LightBuilder.hpp"
#include "MaterialBuilder.hpp"
#include "ObjectBuilder.hpp"

int main(int ac, char **av)
{
    RayTracer::PluginLoader loader;
    loader.LoadPlugins("./plugins");
    RayTracer::Factory<RayTracer::IObject> &objectFactory = loader.getObjectFactory();
    RayTracer::Factory<RayTracer::ILight> &lightFactory = loader.getLightFactory();
    RayTracer::Factory<RayTracer::IMaterial> &materialFactory = loader.getMaterialFactory();

    std::shared_ptr<RayTracer::ILight> al = std::move(lightFactory.createInstance("ambient_light"));
    std::shared_ptr<RayTracer::ILight> dl = std::move(lightFactory.createInstance("directional_light"));

    std::shared_ptr<RayTracer::IMaterial> mat = std::move(materialFactory.createInstance("flat_color"));

    std::shared_ptr<RayTracer::IObject> sphere = std::move(objectFactory.createInstance("sphere"));

    RayTracer::LightBuilder alb(al.get());
    RayTracer::LightBuilder dlb(dl.get());

    RayTracer::MaterialBuilder mb(mat.get());

    RayTracer::ObjectBuilder sb(sphere.get());

    alb.set("intensity", 0.4);
    alb.set("color", RayTracer::Color(1, 0.5, 1));
    return 0;
}
