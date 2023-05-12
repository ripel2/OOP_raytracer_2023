/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** PPMRenderer
*/

#include "PPMRenderer.hpp"

#include <fstream>

RayTracer::PPMRenderer::PPMRenderer(const std::string &filename)
    : _filename(filename), _linesDone(0), _mutex()
{
}

void *RayTracer::PPMRenderer::execRenderThread(std::size_t width, std::size_t height, const Scene &scene, std::size_t start, std::size_t end, std::size_t samplesPerPixel)
{
    for (std::size_t i = start; i < end; i++) {
        for (std::size_t j = 0; j < width; j++) {
            Color color;
            for (std::size_t k = 0; k < samplesPerPixel; k++) {
                for (std::size_t l = 0; l < samplesPerPixel; l++) {
                    double u = (j + (k / static_cast<double>(samplesPerPixel))) / width;
                    double v = 1.0 - (i + (l / static_cast<double>(samplesPerPixel))) / height;
                    color += getColor(u, v, scene);
                }
            }
            color /= samplesPerPixel * samplesPerPixel;
            _image[i].push_back(color);
        }
        _mutex.lock();
        _linesDone++;
        std::cout << "\r" << _linesDone << "/" << height << " lines done";
        _mutex.unlock();
    }
    return nullptr;
}

void RayTracer::PPMRenderer::render(std::size_t width, std::size_t height, const Scene &scene, std::size_t samplesPerPixel)
{
    std::fstream file(_filename, std::ios::out);
    std::vector<std::thread> threads;
    std::size_t thread_nb = 1;
    std::size_t linesPerThread;

    for (std::size_t i = 1; i <= std::thread::hardware_concurrency(); i++) {
        if (height % i == 0) {
            thread_nb = i;
        }
    }
    linesPerThread = height / thread_nb;
    if (!file.is_open())
        throw std::runtime_error("Failed to open file");
    _image.resize(height);
    for (std::size_t i = 0; i < thread_nb; i++) {
        threads.emplace_back(&PPMRenderer::execRenderThread, this, width, height, std::ref(scene), i * linesPerThread, (i + 1) * linesPerThread, samplesPerPixel);
    }
    for (auto &thread : threads) {
        thread.join();
    }
    std::cout << std::endl;
    file << "P3" << std::endl;
    file << width << " " << height << " " << 255 << std::endl;
    for (std::vector<Color> &line : _image) {
        for (Color &color : line) {
            file << (int)(color[0] * 255) << " " << (int)(color[1] * 255) << " " << (int)(color[2] * 255) << " ";
        }
        file << std::endl;
    }
    file.close();
}
