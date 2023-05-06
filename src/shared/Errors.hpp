/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** Errors
*/

#pragma once

#include <iostream>
#include <exception>

namespace RayTracer {
    class Errors : public std::exception {
        public:
            /**
             * @brief Construct a new Errors object
             */
            Errors() = default;
            /**
             * @brief Destroy the Errors object
             */
            ~Errors() = default;

        protected:
            std::string _message;
    };

    class DLLoaderError : public Errors {
        public:
            /**
             * @brief Construct a new DLLoaderError object
             * @param message
             */
            DLLoaderError(std::string const &message) {_message = message;}
            /**
             * @brief Destroy the DLLoaderError object
             */
            const char *what() const noexcept override {return _message.c_str();}
    };

    class FactoryError : public Errors {
        public:
            /**
             * @brief Construct a new FactoryError object
             * @param message
             */
            FactoryError(std::string const &message) {_message = message;}
            /**
             * @brief Destroy the FactoryError object
             */
            const char *what() const noexcept override {return _message.c_str();}
    };

    class BuilderError : public Errors {
        public:
            /**
             * @brief Construct a new BuilderError object
             * @param message
             */
            BuilderError(std::string const &message) {_message = message;}
            /**
             * @brief Destroy the BuilderError object
             */
            const char *what() const noexcept override {return _message.c_str();}
    };

    class PluginLoaderError : public Errors {
        public:
            /**
             * @brief Construct a new PluginLoaderError object
             * @param message
             */
            PluginLoaderError(std::string const &message) {_message = message;}
            /**
             * @brief Destroy the PluginLoaderError object
             */
            const char *what() const noexcept override {return _message.c_str();}
    };
}
