/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** AmbientLight
*/

#pragma once

#include "ILight.hpp"

namespace RayTracer {
    class AmbientLight : public ILight {
        public:
            /**
             * @brief AmbientLight constructor with intensity
             * @param intensity The intensity of the light
             * @note The color of the light will be white
             */
            AmbientLight(double intensity);
            /**
             * @brief AmbientLight constructor with color and intensity
             * @param color The color of the light
             * @param intensity The intensity of the light
            */
            AmbientLight(const RayTracer::Color &color, double intensity);

            /**
             * @brief Apply light to a pixel given a ray and a hit
             * @param pixel The pixel to apply light to
             * @param ray The ray that hit the pixel
             * @param hit The hit information
            */
            RayTracer::Color applyLight(const RayTracer::Color &pixel, const Ray &ray, const RayHit &hit) const override;

        private:
            RayTracer::Color _color;
            double _intensity;
    };
}