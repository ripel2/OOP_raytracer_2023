/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** IRenderer
*/

#pragma once

#include "Color.hpp"

namespace RayTracer {
    class IRenderer {
        public:
            /**
             * @brief IRenderer destructor
            */
            virtual ~IRenderer() = default;

            /**
             * @brief Sets the size of the screen
            */
            virtual void setScreenSize(std::size_t width, std::size_t height) = 0;

            /**
             * @brief Displays a pixel on the screen
             * @param x The x coordinate of the pixel
             * @param y The y coordinate of the pixel
             * @param color The color of the pixel
             * @note The origin is at the top left corner of the screen
            */
            virtual void displayPixel(std::size_t x, std::size_t y, const Color &color) = 0;
    };
}
