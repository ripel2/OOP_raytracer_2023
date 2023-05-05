/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** PointLight
*/

#pragma once

#include "ALight.hpp"

namespace RayTracer {
    class PointLight : public ALight {
        public:
            /**
             * @brief DirectionalLight constructor
            */
            PointLight();

            RayTracer::Color applyLight(const Color &pixel, const Ray &ray,
            const RayHit &hit, const std::vector<std::shared_ptr<RayTracer::IObject>> &objects) const override;

            Math::Point<3> getPosition() const noexcept;

            void setPosition(const Math::Point<3> &position) noexcept;

            RayTracer::Color getColor() const noexcept override;

            void setColor(const RayTracer::Color &color) noexcept override;
        private:
            Math::Point<3> _position;
            RayTracer::Color _color;
    };
}