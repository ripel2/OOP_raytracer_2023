/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** PPMRenderer
*/

#include "PPMRenderer.hpp"

#include <fstream>

RayTracer::PPMRenderer::PPMRenderer(const std::string &filename)
    : filename(filename)
{
}

void RayTracer::PPMRenderer::render(std::size_t width, std::size_t height, const Scene &scene)
{
    std::fstream file(filename, std::ios::out);

    if (!file.is_open())
        throw std::runtime_error("Failed to open file");
    file << "P3" << std::endl;
    file << width << " " << height << " " << 255 << std::endl;
    for (std::size_t i = 0; i < height; i++) {
        for (std::size_t j = 0; j < width; j++) {
            Color color = getColor((double)j / (double)width, (double)i / (double)height, scene);

            file << (int)(color[0] * 255) << " " << (int)(color[1] * 255) << " " << (int)(color[2] * 255) << " ";
        }
        file << std::endl;
    }
    file.close();
}
