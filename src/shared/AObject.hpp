/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** AObject
*/

#pragma once

#include "IObject.hpp"
#include "Matrix.hpp"

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
            virtual bool hits(const Ray &ray, RayHit &hit) const = 0;

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
             * @brief Get the translation matrix of the object
             * @return A const reference to the translation
            */
            const Math::Matrix &getTranslation() const noexcept;

            /**
             * @brief Set the translation of the object
             * @param translation The translation to set
            */
            void setTranslation(const Math::Vector<3> &translation) noexcept;

            /**
             * @brief Get the rotation matrix of the object
             * @return A const reference to the rotation
            */
            const Math::Matrix &getRotation() const noexcept;

            /**
             * @brief Set the rotation of the object
             * @param rotation The rotation to set
            */
            void setRotation(const Math::Vector<3> &rotation) noexcept;

            /**
             * @brief Get the scale matrix of the object
             * @return A const reference to the scale
            */
            const Math::Matrix &getScale() const noexcept;

            /**
             * @brief Set the scale of the object
             * @param scale The scale to set
            */
            void setScale(const Math::Vector<3> &scale) noexcept;

            /**
             * @brief Get the normal vector of the object
             * @return The normal vector
             * @note Used for planes
            */
            virtual Math::Vector<3> getNormal() const noexcept;

            /**
             * @brief Set the normal vector of the object
             * @param normal The normal vector to set
             * @note Used for planes
            */
            virtual void setNormal(const Math::Vector<3> &normal) noexcept;

            /**
             * @brief Get the distance of the object
             * @return The distance of the object
             * @note Used for planes
            */
            virtual Math::Vector<3> getDistance() const noexcept;

            /**
             * @brief Set the distance of the object
             * @param distance The distance to set
             * @note Used for planes
            */
            virtual void setDistance(const Math::Vector<3> &distance) noexcept;

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
        protected:
            /**
             * @brief Get the transformation matrix of the object
             * @return The transformation matrix
             * @note The transformation matrix is the result of the multiplication of the translation, rotation and scale matrices
            */
            Math::Matrix getTransformation() const noexcept;
        private:
            Math::Point<3> _position;
            std::shared_ptr<IMaterial> _material;
            Math::Matrix _translation;
            Math::Matrix _rotation;
            Math::Matrix _scale;
    };
}
