/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** ObjectBuilder
*/

#pragma once

#include <iostream>

#include "AObject.hpp"
#include "Errors.hpp"

namespace RayTracer {
    class ObjectBuilder {
        public:
            /**
             * @brief Construct a new ObjectBuilder object
             * @param object the object to build
            */
            ObjectBuilder(IObject *object);

            /**
             * @brief Destroy the ObjectBuilder object
            */
            ~ObjectBuilder() = default;

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

            /**
             * @brief Call a setter on the object
             * @param name The name of the setter to call
             * @param value The value to pass to the setter
            */
            void set(const std::string &name, const std::shared_ptr<IMaterial> &value);
        private:
            AObject *_object;
    };
}
