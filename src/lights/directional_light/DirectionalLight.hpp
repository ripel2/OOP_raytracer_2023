/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** DirectionalLight
*/

#pragma once

#include "ILight.hpp"

namespace RayTracer {
    class DirectionalLight : public ILight {
        public:
            /**
             * @brief DirectionalLight constructor with direction and intensity
             * @param direction The direction of the light
             * @param intensity The intensity of the light
             * @note The color of the light will be white
            */
            DirectionalLight(const Math::Vector<3> &direction, double intensity);
            /**
             * @brief DirectionalLight constructor with direction, color and intensity
             * @param direction The direction of the light
             * @param color The color of the light
             * @param intensity The intensity of the light
            */
            DirectionalLight(const Math::Vector<3> &direction, const RayTracer::Color &color, double intensity);

            /**
             * @brief Apply light to a pixel given a ray and a hit
             * @param pixel The pixel to apply light to
             * @param ray The ray that hit the pixel
             * @param hit The hit information
            */
            RayTracer::Color applyLight(const RayTracer::Color &pixel, const Ray &ray, const RayHit &hit) const override;

        private:
            Math::Vector<3> _direction;
            RayTracer::Color _color;
            double _intensity;
    };
}