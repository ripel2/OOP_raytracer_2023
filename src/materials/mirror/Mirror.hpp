/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** Mirror
*/

#pragma once

#include "AMaterial.hpp"

namespace RayTracer {
    class Mirror : public AMaterial {
        public:
            /**
             * @brief Mirror constructor
             */
            explicit Mirror();

            /**
             * @brief Mirror destructor
             */
            ~Mirror() override = default;

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

            /**
             * @brief Gets the refraction index of the material
             * @return The refraction index of the material
             */
            [[nodiscard]] double getRefractionIndex() const noexcept override;

            /**
             * @brief Sets the refraction index of the material
             * @param refractionIndex The new refraction index of the material
             */
            void setRefractionIndex(double refractionIndex) noexcept override;
        private:
            Color _color;
            double _refractionIndex;
    };
}
