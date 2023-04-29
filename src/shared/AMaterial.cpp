/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** AMaterial
*/

#include "AMaterial.hpp"

RayTracer::Color RayTracer::AMaterial::getColor() const noexcept
{
    std::cerr << "Warning : Called AMaterial::getColor() function from abstract" << std::endl;
    return RayTracer::Color();
}

void RayTracer::AMaterial::setColor(const RayTracer::Color &color) noexcept
{
    std::cerr << "Warning : Called AMaterial::setColor() function from abstract" << std::endl;
    (void)color;
}

double RayTracer::AMaterial::getAlbedo() const noexcept
{
    std::cerr << "Warning : Called AMaterial::getAlbedo() function from abstract" << std::endl;
    return 0;
}

void RayTracer::AMaterial::setAlbedo(double albedo) noexcept
{
    std::cerr << "Warning : Called AMaterial::setAlbedo() function from abstract" << std::endl;
    (void)albedo;
}

double RayTracer::AMaterial::getFuzziness() const noexcept
{
    std::cerr << "Warning : Called AMaterial::getFuzziness() function from abstract" << std::endl;
    return 0;
}

void RayTracer::AMaterial::setFuzziness(double fuzziness) noexcept
{
    std::cerr << "Warning : Called AMaterial::setFuzziness() function from abstract" << std::endl;
    (void)fuzziness;
}

double RayTracer::AMaterial::getRefractionIndex() const noexcept
{
    std::cerr << "Warning : Called AMaterial::getRefractionIndex() function from abstract" << std::endl;
    return 0;
}

void RayTracer::AMaterial::setRefractionIndex(double refractionIndex) noexcept
{
    std::cerr << "Warning : Called AMaterial::setRefractionIndex() function from abstract" << std::endl;
    (void)refractionIndex;
}
