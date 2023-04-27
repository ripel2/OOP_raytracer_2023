/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Camera
*/

#include "Camera.hpp"

RayTracer::Camera::Camera(const Math::Point<3> &origin, const Math::Point<3> &lookAt,
    const Math::Vector<3> &up, double vfov, double aspectRatio)
    : _origin(origin)
{
    double theta = vfov * M_PI / 180;
    double halfHeight = tan(theta / 2);
    double halfWidth = aspectRatio * halfHeight;
    _w = Math::Vector<3>(origin - lookAt).getNormalized();
    _u = up.cross(_w).getNormalized();
    _v = _w.cross(_u);
    _lowerLeftCorner = _origin - _u * halfWidth - _v * halfHeight - _w;
    _horizontal = _u * 2 * halfWidth;
    _vertical = _v * 2 * halfHeight;
}

RayTracer::Ray RayTracer::Camera::getRay(double u, double v) const
{
    return Ray(_origin, _lowerLeftCorner + _horizontal * u + _vertical * v - _origin);
}
