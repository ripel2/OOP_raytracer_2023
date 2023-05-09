/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SfmlRenderer
*/

#include "SfmlRenderer.hpp"

RayTracer::SfmlRenderer::SfmlRenderer(const std::string &filename)
{
    this->filename = filename;
    this->window.create(sf::VideoMode(1920, 1080), "Raytracer");
    this->window.setFramerateLimit(60);
}

RayTracer::SfmlRenderer::~SfmlRenderer()
{
    this->window.close();
    this->window.~RenderWindow();
}

void RayTracer::SfmlRenderer::render(std::size_t width, std::size_t height, const Scene &scene)
{
    this->window.clear();
    sf::VertexArray array(sf::Points, 1);
    std::size_t index = 0;
    sf::Event event;
    size_t size = 1;
    while (event.type != sf::Event::Closed) {
        for (std::size_t i = 0; i < height; i++) {
            for (std::size_t j = 0; j < width; j++) {
                Color color = getColor((double)j / (double)width, 1.0 - ((double)i / (double)height), scene);
                array[0].position = sf::Vector2f(j, i);
                array[0].color = sf::Color(color[0] * 255, color[1] * 255, color[2] * 255);
                window.draw(&array[0], size, sf::Points);
            }
        }
        window.display();
    }
}