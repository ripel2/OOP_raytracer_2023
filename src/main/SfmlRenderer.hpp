/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Sfml
*/


#pragma once

#include <thread>
#include <mutex>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sys/stat.h>

#include "ARenderer.hpp"

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
            sf::RenderWindow _window;
            sf::Image _image;
            sf::Texture _texture;
            sf::Sprite _sprite;
            sf::View _view;
            std::mutex _mutex;

            /**
             * @brief Handles events
             */
            void event();
            /**
             * @brief Executes a screenshot
             */
            void execScreenshot();
            /**
             * @brief Loads the image
             * @param width The width of the image
             * @param height The height of the image
             * @param scene The scene to render
             */
            void loadImage(std::size_t width, std::size_t height, const Scene &scene);
            /**
             * @brief Renders the image on the window
             */
            void renderImage();
            /**
             * @brief Executes the render thread
             * @param width The width of the image
             * @param height The height of the image
             * @param scene The scene to render
             * @param start The start of the thread
             * @param end The end of the thread
             * @return The image
             */
            void *execRenderThread(std::size_t width, std::size_t height, const Scene &scene, std::size_t start, std::size_t end);
    };
}
