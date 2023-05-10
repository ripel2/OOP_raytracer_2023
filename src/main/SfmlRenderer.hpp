/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Sfml
*/


#pragma once

#include "ARenderer.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>

namespace RayTracer {
    class SfmlRenderer : public ARenderer {
        public:
            /**
             * @brief SfmlRenderer constructor
             * @param filename The filename of the image
             */
            SfmlRenderer(size_t width, size_t height);

            /**
             * @brief SfmlRenderer destructor
             */
            ~SfmlRenderer();

            /**
             * @brief Renders a scene
             * @param width The width of the image
             * @param height The height of the image
             * @param scene The scene to render
             */
            void render(std::size_t width, std::size_t height, const Scene &scene) override;

        private:
            /**
             * @brief The sfml window
             */
            sf::RenderWindow _window;

            /**
             * @brief The sfml image
             */
            sf::Image _image;

            /**
             * @brief The sfml texture
             */
            sf::Texture _texture;

            /**
             * @brief The sfml sprite
             */
            sf::Sprite _sprite;

            /**
             * @brief Zoom on the image
             */
            size_t _zoom = 0;

            /**
             * @brief Event handler
             */
            void event();
    };
}
