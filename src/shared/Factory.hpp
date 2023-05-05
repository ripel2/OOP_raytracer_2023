/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** Factory
*/

#pragma once

#include <map>
#include <memory>
#include <functional>

#include "DLLoader.hpp"
#include "Errors.hpp"

namespace RayTracer {
    template<typename T>
    class Factory {
        public:
            /**
             * @brief Construct a new Factory object
             */
            Factory() = default;
            /**
             * @brief Destroy the Factory object
             */
            ~Factory() = default;

            /**
             * @brief Create an instance of the class
             * @param type
             * @return std::unique_ptr<T>
             */
            std::unique_ptr<T> createInstance(const std::string &type) {
                if (_map.find(type) == _map.end()) {
                    throw FactoryError("Unknown type: " + type);
                }
                return _map.at(type)();
            }
            /**
             * @brief Register a new loader
             * @param type
             * @param loader
             */
            void registerLoader(const std::string &type, DLLoader<T> &loader) {
                if (_map.find(type) != _map.end()) {
                    throw FactoryError("Type already exists: " + type);
                }
                _loaders.push_back(loader);
                _map.emplace(type, std::bind(&DLLoader<T>::getInstance, &loader));
            }
        private:
            std::map<std::string, std::function<std::unique_ptr<T>()>> _map;
            std::vector<DLLoader<T>> _loaders;
    };
}
