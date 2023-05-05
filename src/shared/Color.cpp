/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Color
*/

#include "Color.hpp"

RayTracer::Color::Color(double r, double g, double b)
    : Vector<3>({r, g, b})
{
}

RayTracer::Color::Color(const Math::Vector<3> &color)
    : Vector<3>(color)
{
}

RayTracer::Color::Color(const double (&args)[3])
    : Vector<3>(args)
{
}

void RayTracer::Color::clamp()
{
    for (std::size_t i = 0; i < 3; i++) {
        if (this->_co[i] < 0)
            this->_co[i] = 0;
        if (this->_co[i] > 1)
            this->_co[i] = 1;
    }
}
