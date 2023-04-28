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
#include "Scatter.hpp"

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
            virtual Color getPointColor(const Ray &ray, const RayHit &hit) const = 0;

            /**
             * @brief Get the scatter of the material at a given point
             * @param ray The ray that hit the material
             * @param hit The hit information
             * @param scatter A reference to the scatter to fill
             * @return true if the material got scattered, false otherwise
            */
            virtual bool getScatter(const Ray &ray, const RayHit &hit, Scatter &scatter) const = 0;
        protected:
        private:
    };
}
