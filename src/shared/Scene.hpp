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
            Scene();

            /**
             * @brief Scene destructor
             */
            ~Scene();

            /**
             * @brief Adds an object to the scene
             * @param object The object to add
             */
            void addObject(std::unique_ptr<IObject> &object);

            /**
             * @brief Adds a light to the scene
             * @param light The light to add
             */
            void addLight(std::unique_ptr<ILight> &light);

            /**
             * @brief Sets the camera of the scene
             * @param camera The camera to set
             */
            void setCamera(std::unique_ptr<Camera> &camera);

            /**
             * @brief Gets the objects of the scene
             * @return The objects of the scene
             */
            const std::vector<IObject *> &getObjects() const;

            /**
             * @brief Gets the lights of the scene
             * @return The lights of the scene
             */
            const std::vector<ILight *> &getLights() const;

            /**
             * @brief Gets the camera of the scene
             * @return The camera of the scene
             */
            const Camera *getCamera() const;

        private:
            std::vector<IObject *> _objects;
            std::vector<ILight *> _lights;
            Camera *_camera;
    };
}
