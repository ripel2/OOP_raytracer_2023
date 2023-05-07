/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** Plane
*/

#pragma once

#include "AObject.hpp"

namespace RayTracer {
    class Plane : public AObject {
        public:
            /**
             * @brief Plane constructor
            */
            Plane();

            bool hits(const RayTracer::Ray &ray, RayHit &hit) const override;

            Math::Vector<3> getDistance() const noexcept override;

            void setDistance(const Math::Vector<3> &distance) noexcept override;

            Math::Vector<3> getNormal() const noexcept override;

            void setNormal(const Math::Vector<3> &normal) noexcept override;
        private:
            Math::Vector<3> _distance;
            Math::Vector<3> _normal;
    };
}
