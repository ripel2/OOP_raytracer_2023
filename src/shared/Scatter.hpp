/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** Scatter
*/

#pragma once

#include "Ray.hpp"
#include "Color.hpp"

namespace RayTracer {
    class Scatter {
        public:
            Ray reflected;
            Color attenuation;
            double reflectionIndex;
            double transmissionIndex;
    };
}
