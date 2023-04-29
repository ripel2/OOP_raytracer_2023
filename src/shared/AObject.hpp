/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** AObject
*/

#pragma once

#include "IObject.hpp"

namespace RayTracer {
    class AObject : public IObject {
        public:
            AObject();
            ~AObject() override = default;

            /**
             * @brief Check if the ray hits the object and if it does, return a unique pointer to a RayHit object
             * @param ray The ray to check
             * @return A unique pointer to a RayHit object if the ray hits the object, nullptr otherwise
            */
            virtual bool hits(const Ray &ray, std::unique_ptr<RayHit> &hit) const = 0;

            /**
             * @brief Get the position of the object
             * @return A const reference to the position
            */
            const Math::Point<3> &getPosition() const noexcept;

            /**
             * @brief Set the position of the object
             * @param position The position to set
            */
            void setPosition(const Math::Point<3> &position) noexcept;

            /**
             * @brief Get the material of the object
             * @return A const reference to the material
            */
            const std::shared_ptr<IMaterial> &getMaterial() const noexcept;

            /**
             * @brief Set the material of the object
             * @param material The material to set
            */
            void setMaterial(const std::shared_ptr<IMaterial> &material) noexcept;

            /**
             * @brief Get the radius of the object
             * @return The radius of the object
             * @note Used for spheres, cylinders or the outer radius of a torus
            */
            virtual double getRadius() const noexcept;

            /**
             * @brief Set the radius of the object
             * @param radius The radius to set
             * @note Used for spheres, cylinders or the outer radius of a torus
            */
            virtual void setRadius(double radius) noexcept;

            /**
             * @brief Get the height of the object
             * @return The height of the object
            */
            virtual double getHeight() const noexcept;

            /**
             * @brief Set the height of the object
             * @param height The height to set
            */
            virtual void setHeight(double height) noexcept;

            /**
             * @brief Get the inner radius of the object
             * @return The inner radius of the object
             * @note Used for torus
            */
            virtual double getInnerRadius() const noexcept;

            /**
             * @brief Set the inner radius of the object
             * @param innerRadius The inner radius to set
             * @note Used for torus
            */
            virtual void setInnerRadius(double innerRadius) noexcept;
        private:
            Math::Point<3> _position;
            std::shared_ptr<IMaterial> _material;
    };
}
