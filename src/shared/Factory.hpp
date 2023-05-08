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
                DLLoader<T> *loader = _map[type].get();
                return loader->getInstance();
            }
            /**
             * @brief Register a new loader
             * @param type
             * @param loader
             */
            void registerLoader(const std::string &type, std::unique_ptr<DLLoader<T>> &loader) {
                if (_map.find(type) != _map.end()) {
                    throw FactoryError("Type already exists: " + type);
                }
                _map.emplace(type, std::move(loader));
            }
        private:
            std::map<std::string, std::unique_ptr<DLLoader<T>>> _map;
    };
}
