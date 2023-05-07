/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** RayHit
*/

#pragma once

#include "Point.hpp"

namespace RayTracer {
    struct RayHit {
        Math::Point<3> point;
        Math::Vector<3> normal;
        double distance;
    };
}
