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
            AObject(const Math::Point<3> &position, const std::shared_ptr<RayTracer::IMaterial> &material);

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
            const std::shared_ptr<RayTracer::IMaterial> &getMaterial() const noexcept;

            /**
             * @brief Set the material of the object
             * @param material The material to set
            */
            void setMaterial(const std::shared_ptr<RayTracer::IMaterial> &material) noexcept;

        private:
            Math::Point<3> _position;
            std::shared_ptr<RayTracer::IMaterial> _material;

    };
}