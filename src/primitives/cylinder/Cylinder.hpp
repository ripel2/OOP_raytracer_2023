/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Cylinder
*/

#pragma once

#include "AObject.hpp"

namespace RayTracer {
    class Cylinder : public AObject {
        public:
            /**
             * @brief Cylinder constructor
            */
            Cylinder();

            bool hits(const RayTracer::Ray &ray, RayHit &hit) const override;

            double getRadius() const noexcept override;

            void setRadius(double radius) noexcept override;

            double getHeight() const noexcept override;

            void setHeight(double height) noexcept override;
        private:
            double _radius;
            double _height;

            bool _hitsSide(const RayTracer::Ray &ray, RayHit &hit) const;
            bool _hitsTop(const RayTracer::Ray &ray, RayHit &hit) const;
            bool _hitsBottom(const RayTracer::Ray &ray, RayHit &hit) const;
    };
}
