/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** ALight
*/

#pragma once

#include "ILight.hpp"

namespace RayTracer {
    class ALight : public ILight {
        public:
            /**
             * @brief ALight constructor
            */
            ALight();
            /**
             * @brief ALight destructor
            */
            ~ALight() override = default;

            /**
             * @brief Apply light to a pixel given a ray and a hit
             * @param pixel The pixel to apply light to
             * @param ray The ray that hit the pixel
             * @param hit The hit information
            */
            virtual Color applyLight(const Color &pixel, const Ray &ray, const RayHit &hit) const = 0;

            /**
             * @brief Get the intensity of the light
             * @return The intensity of the light
             * @note The intensity is a value between 0 and 1
            */
            double getIntensity() const noexcept;

            /**
             * @brief Set the intensity of the light
             * @param intensity The intensity to set
             * @note The intensity is a value between 0 and 1
            */
            void setIntensity(double intensity);

            /**
             * @brief Get the color of the light
             * @return The color of the light
            */
            virtual const Color &getColor() const noexcept = 0;

            /**
             * @brief Set the color of the light
             * @param color The color to set
            */
            virtual void setColor(const Color &color) noexcept = 0;

            /**
             * @brief Get the directional vector of the light
             * @return The directional vector of the light
             * @note The directional vector is a normalized vector, used for directional lights
             * and spotlights
            */
            virtual const Math::Vector<3> &getDirection() const noexcept = 0;

            /**
             * @brief Set the directional vector of the light
             * @param direction The directional vector to set
             * @note The directional vector is a normalized vector, used for directional lights
             * and spotlights
            */
            virtual void setDirection(const Math::Vector<3> &direction) noexcept = 0;

            /**
             * @brief Get the position of the light
             * @return The position of the light
             * @note The position is a point, used for point lights and spotlights
            */
            virtual const Math::Point<3> &getPosition() const noexcept = 0;

            /**
             * @brief Set the position of the light
             * @param position The position to set
             * @note The position is a point, used for point lights and spotlights
            */
            virtual void setPosition(const Math::Point<3> &position) noexcept = 0;

        protected:
            double _intensity;
            Color _color;
    };
}