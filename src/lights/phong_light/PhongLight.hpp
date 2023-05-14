/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** PhongLight
*/

#pragma once

#include "ALight.hpp"

namespace RayTracer {
    class PhongLight : public ALight {
        public:
            PhongLight();

            RayTracer::Color applyLight(const Color &pixel, const Ray &ray,
            const RayHit &hit, const std::vector<RayTracer::IObject *> &objects) const override;
        private:
            Color _applyAmbientLight(const Color &pixel, const Ray &ray, const RayHit &hit,
            const std::vector<RayTracer::IObject *> &objects) const;
            Color _applyDiffuseLight(const Color &pixel, const Ray &ray, const RayHit &hit,
            const std::vector<RayTracer::IObject *> &objects) const;
            Color _applySpecularLight(const Color &pixel, const Ray &ray, const RayHit &hit,
            const std::vector<RayTracer::IObject *> &objects) const;
            Color _color;
            Math::Vector<3> _direction;
    };
}
