/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL : Ubuntu-20.04]
** File description:
** Entrypoint
*/

#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "ILight.hpp"
#include "AmbientLight.hpp"
#include "PluginLoader.hpp"

extern "C" std::unique_ptr<RayTracer::ILight> getInstance()
{
    std::unique_ptr<RayTracer::ILight> instance = std::make_unique<RayTracer::AmbientLight>();
    std::cout << "Owned ptr: " << instance.get() << std::endl;
    return instance;
}

extern "C" std::unique_ptr<RayTracer::pluginType_t> getType()
{
    return std::make_unique<RayTracer::pluginType_t>(RayTracer::pluginType_t::LIGHT);
}

extern "C" std::unique_ptr<std::string> getName()
{
    return std::make_unique<std::string>("ambient_light");
}

extern "C" std::unique_ptr<RayTracer::pluginType_t> getType()
{
    return std::make_unique<RayTracer::pluginType_t>(RayTracer::pluginType_t::LIGHT);
}

extern "C" std::unique_ptr<std::string> getName()
{
    return std::make_unique<std::string>("ambient_light");
}
