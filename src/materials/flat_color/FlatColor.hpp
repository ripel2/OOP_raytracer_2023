/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** FlatColor
*/

#pragma once

#include "AMaterial.hpp"

namespace RayTracer {
    class FlatColor : public AMaterial {
        public:
            /**
             * @brief FlatColor constructor
             */
            explicit FlatColor();

            /**
             * @brief FlatColor destructor
             */
            ~FlatColor() override = default;

            /**
             * @brief Gets the color of the material
             * @param rayHit The ray hit
             * @return The color of the material
             */
            [[nodiscard]] Color getPointColor(const Ray &ray, const RayHit &hit) const;

            /**
             * @brief Gets the scatter of the material
             * @param ray The ray that hit the material
             * @param rayHit The ray hit
             * @param scatter A reference to the scatter to fill
             * @return true if the material got scattered, false otherwise
             */
            bool getScatter(const Ray &ray, const RayHit &hit, Scatter &scatter) const;

            /**
             * @brief Gets the color of the material
             * @return The color of the material
             */
            [[nodiscard]] Color getColor() const noexcept;

            /**
             * @brief Sets the color of the material
             * @param color The new color of the material
             */
            void setColor(const Color &color) noexcept;
        private:
            Color _color;
    };
}
