/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Cone
*/

#pragma once

#include "AObject.hpp"

namespace RayTracer {
    class Cone : public AObject {
        public:
            /**
             * @brief Cone constructor
            */
            Cone();

            bool hits(const RayTracer::Ray &ray, RayHit &hit) const override;

            double getRadius() const noexcept override;

            void setRadius(double radius) noexcept override;

            double getHeight() const noexcept override;

            void setHeight(double height) noexcept override;
        private:
            double _radius;
            double _height;

            bool _hitsSide(const RayTracer::Ray &ray, RayHit &hit) const;
            bool _hitsCap(const RayTracer::Ray &ray, RayHit &hit, bool offsetBottom) const;
    };
}
