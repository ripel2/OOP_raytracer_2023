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

            /**
             * @brief Apply light to a pixel with a point light
             * @param pixel The pixel to apply light to
             * @param ray The ray to apply light to
             * @param hit The hit information
             * @param objects The objects in the scene
             * @return The pixel with light applied
            */
            RayTracer::Color applyLight(const Color &pixel, const Ray &ray,
            const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const override;

            Math::Point<3> getPosition() const noexcept override;

            void setPosition(const Math::Point<3> &position) noexcept override;

            RayTracer::Color getColor() const noexcept override;

            void setColor(const RayTracer::Color &color) noexcept override;

            double getShadowRayOffset() const noexcept override;

            void setShadowRayOffset(double offset) noexcept override;

            int getShadowRayCount() const noexcept override;

            void setShadowRayCount(int count) noexcept override;
        private:
            Math::Point<3> _position;
            RayTracer::Color _color;
            double _shadowRayOffset;
            int _shadowRayCount;

            /**
             * @brief Apply light to a pixel with a point light without any offset (no soft shadows)
             * @param pixel The pixel to apply light to
             * @param ray The ray that hit the pixel
             * @param hit The hit information
             * @param objects The objects in the scene
             * @return The pixel with the light applied
            */
            RayTracer::Color _applyLightMain(const Color &pixel, const Ray &ray,
            const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const;

            /**
             * @brief Apply light to a pixel with a point light with an offset (soft shadows)
             * @param pixel The pixel to apply light to
             * @param ray The ray that hit the pixel
             * @param hit The hit information
             * @param objects The objects in the scene
             * @param offset The offset to apply to the light
             * @return The pixel with the light applied
            */
            RayTracer::Color _applyLightOffset(const Color &pixel, const Ray &ray,
            const RayHit &hit, const std::vector<RayTracer::IObject *> &objects, const Math::Point<3> &offset) const;
    };
}
