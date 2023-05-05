/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** RayHit
*/

#pragma once

#include "Point.hpp"
#include "IObject.hpp"

#include <memory>

namespace RayTracer {
    class IObject;

    class RayHit {
        public:
            Math::Point<3> point;
            Math::Vector<3> normal;
            double distance;
            std::shared_ptr<IObject> object;

    };
}
