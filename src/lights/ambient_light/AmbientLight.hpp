/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** AmbientLight
*/

#pragma once

#include "ALight.hpp"

namespace RayTracer {
    class AmbientLight : public ALight {
        public:
            /**
             * @brief AmbientLight constructor
             */
            AmbientLight();

            RayTracer::Color applyLight(const Color &pixel, const Ray &ray,
            const RayHit &hit, const std::vector<std::shared_ptr<RayTracer::IObject>> &objects) const override;

            RayTracer::Color getColor() const noexcept override;

            void setColor(const RayTracer::Color &color) noexcept override;
        private:
            RayTracer::Color _color;
    };
}