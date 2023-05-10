/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** PPMRenderer
*/

#pragma once

#include "thread"
#include "mutex"

#include "ARenderer.hpp"

namespace RayTracer {
    class PPMRenderer : public ARenderer {
        public:
            /**
             * @brief PPMRenderer constructor
             * @param filename The filename of the image
             */
            explicit PPMRenderer(const std::string &filename);

            /**
             * @brief PPMRenderer destructor
             */
            ~PPMRenderer() override = default;

            /**
             * @brief Renders a scene
             * @param width The width of the image
             * @param height The height of the image
             * @param scene The scene to render
             */
            void render(std::size_t width, std::size_t height, const Scene &scene) override;

        private:
            std::string _filename;
            std::vector<std::vector<Color>> _image;
            std::size_t _linesDone;
            std::mutex _mutex;
            /**
             * @brief The function executed by each thread
             * @param width The width of the image
             * @param height The height of the image
             * @param scene The scene to render
             * @param start The start of the lines to render
             * @param end The end of the lines to render
             * @return nullptr
             */
            void *execRenderThread(std::size_t width, std::size_t height, const Scene &scene, std::size_t start, std::size_t end);
    };
}