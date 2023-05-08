/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** DLLoader
*/

#pragma once

#include <dlfcn.h>
#include <iostream>
#include <memory>

#include "Errors.hpp"

namespace RayTracer {
    template<typename T>
    class DLLoader {
        public:
            /**
             * @brief Construct a new DLLoader object
             * @param path
             */
            DLLoader(const std::string &path)
            : _handle(dlopen(path.c_str(), RTLD_LAZY)) {
                if (!_handle) {
                    throw DLLoaderError("cannot load library: " + std::string(dlerror()));
                }
            }
            /**
             * @brief Destroy the DLLoader object
             */
            ~DLLoader() {dlclose(_handle);}
            /**
             * @brief Load the instance of the class
             * @param entryPoint
             */
            void loadInstance(const std::string &entryPoint) {
                _entrypoint = reinterpret_cast<std::unique_ptr<T> (*)(void)>(dlsym(_handle, entryPoint.c_str()));
                if (!_entrypoint) {
                    throw DLLoaderError("cannot load symbol: " + std::string(dlerror()));
                }
            }
            /**
             * @brief Get the Instance object
             * @return std::unique_ptr<T>
             */
            std::unique_ptr<T> getInstance() {
                return _entrypoint();
            }
        private:
            void *_handle;
            std::unique_ptr<T> (*_entrypoint)(void);
    };
}
