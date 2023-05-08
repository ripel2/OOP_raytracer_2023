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
            virtual Color applyLight(const Color &pixel, const Ray &ray,
            const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const = 0;

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
            virtual Color getColor() const noexcept;

            /**
             * @brief Set the color of the light
             * @param color The color to set
            */
            virtual void setColor(const Color &color) noexcept;

            /**
             * @brief Get the directional vector of the light
             * @return The directional vector of the light
             * @note The directional vector is a normalized vector, used for directional lights
             * and spotlights
            */
            virtual Math::Vector<3> getDirection() const noexcept;

            /**
             * @brief Set the directional vector of the light
             * @param direction The directional vector to set
             * @note The directional vector is a normalized vector, used for directional lights
             * and spotlights
            */
            virtual void setDirection(const Math::Vector<3> &direction) noexcept;

            /**
             * @brief Get the position of the light
             * @return The position of the light
             * @note The position is a point, used for point lights and spotlights
            */
            virtual Math::Point<3> getPosition() const noexcept;

            /**
             * @brief Set the position of the light
             * @param position The position to set
             * @note The position is a point, used for point lights and spotlights
            */
            virtual void setPosition(const Math::Point<3> &position) noexcept;

            /**
             * @brief Get the shadow ray offset of the light
             * @return The shadow ray offset of the light
             * @note The shadow ray offset is the maximum distance to create random shadow rays 
             * from the light position
            */
            virtual double getShadowRayOffset() const noexcept;

            /**
             * @brief Set the shadow ray offset of the light
             * @param shadowRayOffset The shadow ray offset to set
             * @note The shadow ray offset is the maximum distance to create random shadow rays
             * from the light position
            */
            virtual void setShadowRayOffset(double shadowRayOffset) noexcept;

            /**
             * @brief Get the shadow ray bias of the light
             * @return The shadow ray bias of the light
             * @note The shadow ray bias is the number of rays to cast to check if a point is in shadow
             * it is used for point lights and spotlights
            */
            virtual int getShadowRayCount() const noexcept;

            /**
             * @brief Set the shadow ray bias of the light
             * @param shadowRayCount The shadow ray bias to set
             * @note The shadow ray bias is the number of rays to cast to check if a point is in shadow
             * it is used for point lights and spotlights
            */
            virtual void setShadowRayCount(int shadowRayCount) noexcept;

        protected:
            double _intensity;
    };
}
