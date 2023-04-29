/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** DirectionalLight
*/

#pragma once

#include "ALight.hpp"

namespace RayTracer {
    class DirectionalLight : public ALight {
        public:
            /**
             * @brief DirectionalLight constructor
            */
            DirectionalLight();

            RayTracer::Color applyLight(const RayTracer::Color &pixel, const Ray &ray, const RayHit &hit) const override;

            Math::Vector<3> getDirection() const noexcept;

            void setDirection(const Math::Vector<3> &direction) noexcept;

            RayTracer::Color getColor() const noexcept override;

            void setColor(const RayTracer::Color &color) noexcept override;
        private:
            Math::Vector<3> _direction;
            RayTracer::Color _color;
    };
}