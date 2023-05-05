/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** IObject
*/

#pragma once

#include "Ray.hpp"
#include "RayHit.hpp"
#include "IMaterial.hpp"

#include <memory>

namespace RayTracer {
    class IObject {
        public:
            /**
             * @brief IObject destructor
            */
            virtual ~IObject() = default;

            /**
             * @brief Check if the ray hits the object and if it does, return a unique pointer to a RayHit object
             * @param ray The ray to check
             * @return A unique pointer to a RayHit object if the ray hits the object, nullptr otherwise
            */
            virtual bool hits(const Ray &ray, RayHit &hit) const = 0;

            /**
             * @brief Get the material of the object
             * @return A const reference to the material
            */
            virtual const std::shared_ptr<IMaterial> &getMaterial() const noexcept = 0;
    };
}
