/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** ARenderer
*/

#pragma once

#include "IRenderer.hpp"
#include "Scene.hpp"
#include "Ray.hpp"
#include "Color.hpp"
#include "RayHit.hpp"

namespace RayTracer {
    class ARenderer : public IRenderer {
        public:
            /**
             * @brief ARenderer constructor
             */
            ARenderer();
            /**
             * @brief ARenderer destructor
             */
            ~ARenderer() override = default;

            /**
             * @brief Renders a scene
             * @param width The width of the image
             * @param height The height of the image
             * @param scene The scene to render
             */
            virtual void render(std::size_t width, std::size_t height, const Scene &scene, std::size_t samplesPerPixel, std::size_t depth) = 0;

        protected:
            /**
             * @brief Gets the color of a pixel
             * @param u The u coordinate of the pixel
             * @param v The v coordinate of the pixel
             * @param scene The scene to render
             * @return The color of the pixel
             */
            [[nodiscard]] Color getColor(double u, double v, const Scene &scene, std::size_t depth);

            /**
             * @brief Gets the color of a pixel
             * @param ray The ray to cast
             * @param scene The scene to render
             * @return The color of the pixel
             */
            [[nodiscard]] Color getColor(const Ray &ray, const Scene &scene, std::size_t depth, IObject *lastObject = nullptr);
        
        private:
            std::size_t _seed;

            /**
             * @brief Gets a random point in a unit sphere
             * @return The random point
            */
            Math::Vector<3> randomInUnitSphere();
    };
}
