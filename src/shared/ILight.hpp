/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** ILight
*/

#pragma once

#include "Ray.hpp"
#include "RayHit.hpp"
#include "Color.hpp"
#include "Point.hpp"
#include "Vector.hpp"
#include "IObject.hpp"

#include <vector>

namespace RayTracer {
    class ILight {
        public:
            /**
             * @brief ILight destructor
            */
            virtual ~ILight() = default;

            /**
             * @brief Apply light to a pixel given a ray and a hit
             * @param pixel The pixel to apply light to
             * @param ray The ray that hit the pixel
             * @param hit The hit information
            */
            virtual RayTracer::Color applyLight(const Color &pixel, const Ray &ray,

            const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const = 0;
    };
}
