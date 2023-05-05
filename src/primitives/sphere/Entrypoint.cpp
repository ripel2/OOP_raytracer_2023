/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL : Ubuntu-20.04]
** File description:
** Entrypoint
*/

#include <iostream>
#include <memory>
#include "IObject.hpp"
#include "Sphere.hpp"

extern "C" std::unique_ptr<RayTracer::IObject> primitiveEntryPoint()
{
    return std::make_unique<RayTracer::Sphere>();
}
