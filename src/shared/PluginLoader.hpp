/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** PluginLoader
*/

#pragma once

#include <filesystem>

#include "DLLoader.hpp"
#include "IMaterial.hpp"
#include "ILight.hpp"
#include "IObject.hpp"
#include "Factory.hpp"

namespace RayTracer {
    typedef enum pluginType_e {
        OBJECT = 0,
        LIGHT = 1,
        MATERIAL = 2
    } pluginType_t;

    class PluginLoader {
        public:
            /**
             * @brief Construct a new PluginLoader object
             */
            PluginLoader() = default;
            /**
             * @brief Destroy the PluginLoader object
             */
            ~PluginLoader() = default;

            /**
             * @brief Load all plugins from a directory
             * @param path
             */
            void LoadPlugins(const std::string &path);

            /**
             * @brief Get the Object Factory object
             * @return Factory<IObject>&
             */
            Factory<IObject> &getObjectFactory();
            /**
             * @brief Get the Light Factory object
             * @return Factory<ILight>&
             */
            Factory<ILight> &getLightFactory();
            /**
             * @brief Get the Material Factory object
             * @return Factory<IMaterial>&
             */
            Factory<IMaterial> &getMaterialFactory();
        private:
            /**
             * @brief Load a plugin
             * @param path
             * @param factory
             */
            template<typename T>
            void LoadPlugin(const std::string &path, Factory<T> &factory)
            {
                DLLoader<std::string> nameLoader(path);
                DLLoader<T> objectLoader(path);

                nameLoader.loadInstance("getName");
                objectLoader.loadInstance("getInstance");
                factory.registerLoader((*nameLoader.getInstance()), objectLoader);
            }
            Factory<IObject> _objectFactory;
            Factory<ILight> _lightFactory;
            Factory<IMaterial> _materialFactory;
    };
}
