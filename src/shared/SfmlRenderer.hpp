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
            SfmlRenderer(const std::string &filename);

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
             * @brief The filename of the image
             */
            std::string filename;
            /**
             * @brief The sfml window
             */
            sf::RenderWindow window;
    };
}
