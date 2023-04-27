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
            Sphere(const Math::Point<3> &center, std::shared_ptr<IMaterial> &material, double radius);

            bool hits(const RayTracer::Ray &ray, std::unique_ptr<RayTracer::RayHit> &hit) const;
        private:
            Math::Point<3> _center;
            double _radius;
    };
}