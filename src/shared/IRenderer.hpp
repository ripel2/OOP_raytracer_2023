/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** IRenderer
*/

#pragma once

#include "Scene.hpp"

namespace RayTracer {
    class IRenderer {
        public:
            /**
             * @brief IRenderer destructor
             */
            virtual ~IRenderer() = default;

            /**
             * @brief Renders a scene
             * @param width The width of the image
             * @param height The height of the image
             * @param scene The scene to render
             */
            virtual void render(std::size_t width, std::size_t height, const Scene &scene) = 0;
    };
}
