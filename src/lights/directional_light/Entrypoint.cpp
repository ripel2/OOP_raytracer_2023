/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL : Ubuntu-20.04]
** File description:
** Entrypoint
*/

#include <iostream>
#include <memory>
#include "ILight.hpp"
#include "DirectionalLight.hpp"

extern "C" std::unique_ptr<RayTracer::ILight> lightEntryPoint()
{
    return std::make_unique<RayTracer::DirectionalLight>();
}
