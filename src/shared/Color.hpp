/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Color
*/

#pragma once

#include "Vector.hpp"

namespace RayTracer {
    class Color : public Math::Vector<3> {
        public:
            /**
             * @brief Color constructor
             * @param r The red component
             * @param g The green component
             * @param b The blue component
             */
            Color(double r = 0, double g = 0, double b = 0);

            /**
             * @brief Color constructor
             * @param color The color vector
             */
            Color(const Math::Vector<3> &color);

            /**
             * @brief Color constructor
             * @param args The color components
             */
            Color(const double (&args)[3]);

            /**
             * @brief Clamps the color components to values between 0 and 1
            */
            void clamp();
    };
}
