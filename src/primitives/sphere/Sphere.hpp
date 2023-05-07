/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Sphere
*/

#pragma once

#include "AObject.hpp"

namespace RayTracer {
    class Sphere : public AObject {
        public:
            /**
             * @brief Sphere constructor
            */
            Sphere();

            bool hits(const RayTracer::Ray &ray, RayHit &hit) const override;

            virtual double getRadius() const noexcept;

            void setRadius(double radius) noexcept;
        private:
            double _radius;
    };
}
