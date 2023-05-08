/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** LightBuilder
*/

#pragma once

#include "ILight.hpp"
#include "ALight.hpp"
#include "Errors.hpp"

namespace RayTracer {
    class LightBuilder {
        public:
            /**
             * @brief Construct a new LightBuilder object
             * @param light the object to build
            */
            LightBuilder(ILight *light);
    
            /**
             * @brief Destroy the LightBuilder object
            */
            ~LightBuilder() = default;

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

            void set(const std::string &name, const int &value);

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
            ALight *_light;
    };
}
