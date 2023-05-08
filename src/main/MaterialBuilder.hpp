/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** MaterialBuilder
*/

#pragma once

#include <iostream>

#include "AMaterial.hpp"
#include "Errors.hpp"

namespace RayTracer {
    class MaterialBuilder {
        public:
            /**
             * @brief Construct a new MaterialBuilder object
             * @param material the material to build
            */
            MaterialBuilder(IMaterial *light);

            /**
             * @brief Destroy the MaterialBuilder object
            */
            ~MaterialBuilder() = default;

            /**
             * @brief Call a setter on the object
             * @param name The name of the setter to call
             * @param value The value to pass to the setter
            */
            void set(const std::string &name, const double &value);

            /**
             * @brief Call a setter on the object
             * @param name The name of the setter to call
             * @param value The value to pass to the setter
            */
            void set(const std::string &name, const Color &value);

            /**
             * @brief Call a setter on the object
             * @param name The name of the setter to call
             * @param value The value to pass to the setter
            */
            void set(const std::string &name, const Math::Vector<3> &value);

            /**
             * @brief Call a setter on the object
             * @param name The name of the setter to call
             * @param value The value to pass to the setter
            */
            void set(const std::string &name, const Math::Point<3> &value);
        private:
            AMaterial *_material;
    };
}