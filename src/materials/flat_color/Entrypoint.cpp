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

#include "IObject.hpp"
#include "FlatColor.hpp"
#include "PluginType.hpp"

extern "C" std::unique_ptr<RayTracer::IMaterial> getInstance()
{
    return std::make_unique<RayTracer::FlatColor>();
}

extern "C" std::unique_ptr<RayTracer::pluginType_t> getType()
{
    return std::make_unique<RayTracer::pluginType_t>(RayTracer::pluginType_t::MATERIAL);
}

extern "C" std::unique_ptr<std::string> getName()
{
    return std::make_unique<std::string>("flat_color");
}
