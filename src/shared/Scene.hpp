/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** Scene
*/

#pragma once

#include <vector>

#include "IObject.hpp"
#include "ILight.hpp"
#include "Camera.hpp"

namespace RayTracer {
    class Scene {
        public:
            /**
             * @brief Scene constructor
             */
            Scene() = default;

            /**
             * @brief Scene destructor
             */
            ~Scene() = default;

            /**
             * @brief Adds an object to the scene
             * @param object The object to add
             */
            void addObject(const std::shared_ptr<IObject> &object);

            /**
             * @brief Adds a light to the scene
             * @param light The light to add
             */
            void addLight(const std::shared_ptr<ILight> &light);

            /**
             * @brief Sets the camera of the scene
             * @param camera The camera to set
             */
            void setCamera(const std::shared_ptr<Camera> &camera);

            /**
             * @brief Gets the objects of the scene
             * @return The objects of the scene
             */
            const std::vector<std::shared_ptr<IObject>> &getObjects() const;

            /**
             * @brief Gets the lights of the scene
             * @return The lights of the scene
             */
            const std::vector<std::shared_ptr<ILight>> &getLights() const;

            /**
             * @brief Gets the camera of the scene
             * @return The camera of the scene
             */
            const std::shared_ptr<Camera> &getCamera() const;

        private:
            std::vector<std::shared_ptr<IObject>> _objects;
            std::vector<std::shared_ptr<ILight>> _lights;
            std::shared_ptr<Camera> _camera;
    };
}
