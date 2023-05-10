/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SfmlRenderer
*/

#include "SfmlRenderer.hpp"

RayTracer::SfmlRenderer::SfmlRenderer(size_t width, size_t height)
{
    this->_window.create(sf::VideoMode(width, height), "Raytracer");
    this->_window.setFramerateLimit(60);
    this->_image.create(width, height, sf::Color::Black);
    this->_texture.loadFromImage(_image);
    this->_sprite.setTexture(_texture);
}

RayTracer::SfmlRenderer::~SfmlRenderer()
{
    this->_window.~RenderWindow();
}

void RayTracer::SfmlRenderer::event()
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                _window.close();
            }
            if (event.key.code == sf::Keyboard::P) {
                _zoom++;
            }
            if (event.key.code == sf::Keyboard::L) {
                _zoom--;
            }
        }
    }
}

void RayTracer::SfmlRenderer::render(std::size_t width, std::size_t height, const Scene &scene)
{
    this->_window.clear();
    size_t size = 1;

    while (_window.isOpen()) {
        for (std::size_t i = 0; i < height; i++) {
            for (std::size_t j = 0 ; j < width; j++) {
                printf("i: %ld/%d, j: %ld/%d\n", i, height, j, width);
                event();
                Color color = getColor((double)j / (double)width, 1.0 - ((double)i / (double)height), scene);
                _image.setPixel(j, i, sf::Color(color[0] * 255, color[1] * 255, color[2] * 255));
                _texture.loadFromImage(_image);
                _sprite.setTexture(_texture);
                _window.clear();
                _window.draw(_sprite);
                _window.display();
            }
        }
    }
}