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

            /**
             * @brief Ray constructor
            */
            Ray();

            /**
             * @brief Ray constructor with arguments
             * @param origin The origin point of the ray
             * @param direction The direction vector of the ray
            */
            Ray(const Math::Point<3> &origin, const Math::Vector<3> &direction);

            /**
             * @brief Ray copy constructor
            */
            Ray(const Ray &ray);

            /**
             * @brief Ray move constructor
            */
            Ray(Ray &&ray);

            /**
             * @brief Ray copy assignment operator
            */
            Ray &operator=(const Ray &ray);

            /**
             * @brief Ray move assignment operator
            */
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
