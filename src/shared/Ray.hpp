/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Ray
*/

#pragma once

#include "Vector.hpp"
#include "Point.hpp"
#include "Matrix.hpp"

namespace RayTracer {
    class Ray {
        public:
            Math::Point<3> _origin;
            Math::Vector<3> _direction;

            Ray();

            Ray(const Math::Point<3> &origin, const Math::Vector<3> &direction);

            Ray(const Ray &ray);

            Ray(Ray &&ray);

            Ray &operator=(const Ray &ray);

            Ray &operator=(Ray &&ray);

            /**
             * @brief Get the origin point of the ray
             * @return A const reference to the origin point
            */
            const Math::Point<3> &getOrigin() const noexcept;
            /**
             * @brief Get the direction vector of the ray
             * @return A const reference to the direction vector
            */
            const Math::Vector<3> &getDirection() const noexcept;

            /**
             * @brief Get the point at a given distance from the origin
             * @param distance The distance from the origin
            */
            Math::Point<3> getPoint(double distance) const;
    };
}
