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
    auto theta = vfov * M_PI / 180;
    auto h = tan(theta / 2);
    auto viewportHeight = 2.0 * h;
    auto viewportWidth = aspectRatio * viewportHeight;

    _w = Math::Vector<3>(origin - lookAt).getNormalized();
    if (std::abs(up.dot(_w)) == 1.0) {
        _u = Math::Vector<3>({1, 0, 0});
    } else {
        _u = up.cross(_w).getNormalized();
    }
    _v = _w.cross(_u);

    _horizontal = _u * viewportWidth;
    _vertical = _v * viewportHeight;
    _lowerLeftCorner = _origin - _horizontal / 2 - _vertical / 2 - _w;
}

RayTracer::Ray RayTracer::Camera::getRay(double u, double v) const
{
    Math::Vector<3> dir = _lowerLeftCorner + _horizontal * u + _vertical * v - _origin;

    dir.normalize();
    return Ray(_origin, dir);
}
