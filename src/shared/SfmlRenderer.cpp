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
    sf::VertexArray array(sf::Points, width * height);
    std::size_t index = 0;
    sf::Event event;
    size_t size = 1;

    for (std::size_t i = 0; i < height; i++) {
        printf("Rendering line %ld/%ld\n", i, height);
        for (std::size_t j = 0; j < width; j++) {
            Color color = getColor((double)j / (double)width, 1.0 - ((double)i / (double)height), scene);
            array[index].position = sf::Vector2f(j, i);
            array[index].color = sf::Color(color[0] * 255, color[1] * 255, color[2] * 255);
            window.draw(&array[index], size, sf::Points);
        }
    }
    window.display();
    while (event.type != sf::Event::Closed) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}