/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Camera
*/

#pragma once

#include "Point.hpp"
#include "Vector.hpp"
#include "Ray.hpp"

namespace RayTracer {
    class Camera {
        public:
            /**
             * @brief Camera object constructor
             * @param origin The origin of the camera
             * @param lookAt The point the camera is looking at
             * @param up The up vector of the camera
             * @param vfov The vertical field of view of the camera
             * @param aspectRatio The aspect ratio of the camera
             * @return A new Camera object
            */
            Camera(const Math::Point<3> &origin, const Math::Point<3> &lookAt,
            const Math::Vector<3> &up, double vfov, double aspectRatio);

            /**
             * @brief Get a ray for a given point on the screen
             * @param u The horizontal position of the point
             * @param v The vertical position of the point
             * @return The ray for the given point
            */
            RayTracer::Ray getRay(double u, double v) const;

        private:
            Math::Point<3> _origin;
            Math::Vector<3> _horizontal;
            Math::Vector<3> _vertical;
            Math::Point<3> _lowerLeftCorner;
            Math::Vector<3> _u, _v, _w;
    };
}
