/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** IMaterial
*/

#pragma once

#include "Ray.hpp"
#include "RayHit.hpp"
#include "Color.hpp"

namespace RayTracer {
    class IMaterial {
        public:
            /**
             * @brief IMaterial destructor
            */
            virtual ~IMaterial() = default;

            /**
             * @brief Get the color of the material at a given point
             * @param ray The ray that hit the material
             * @param hit The hit information
             * @return The color of the material at the given point
            */
            virtual Color getColor(const RayTracer::Ray &ray, const RayTracer::RayHit &hit) const = 0;
        protected:
        private:
    };
}
