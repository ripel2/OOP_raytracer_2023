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

extern "C" std::unique_ptr<RayTracer::ILight> lightEntryPoint()
{
    return std::make_unique<RayTracer::AmbientLight>();
}
