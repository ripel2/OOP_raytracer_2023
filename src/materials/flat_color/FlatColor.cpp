/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** FlatColor
*/

#include "FlatColor.hpp"

RayTracer::Color RayTracer::FlatColor::getPointColor(const RayTracer::Ray &ray, const RayTracer::RayHit &hit) const
{
    (void)ray;
    (void)hit;
    return getColor();
}

bool RayTracer::FlatColor::getScatter(const RayTracer::Ray &ray, const RayTracer::RayHit &hit, RayTracer::Scatter &scatter) const
{
    (void)ray;
    (void)hit;
    (void)scatter;
    return false;
}

RayTracer::Color RayTracer::FlatColor::getColor() const noexcept
{
    return _color;
}

void RayTracer::FlatColor::setColor(const RayTracer::Color &color) noexcept
{
    _color = color;
}
