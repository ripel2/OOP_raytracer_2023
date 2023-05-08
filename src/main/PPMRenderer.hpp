/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** PPMRenderer
*/

#pragma once

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
            /**
             * @brief The filename of the image
             */
            std::string filename;
    };
}