/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023
** File description:
** Parser
*/

#pragma once

#include <libconfig.h++>

#include "PluginLoader.hpp"
#include "Errors.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "ARenderer.hpp"
#include "PPMRenderer.hpp"

namespace RayTracer {
    class Parser {
        private:
            PluginLoader *_loader;
            std::size_t _imageWidth;
            std::size_t _imageHeight;
            std::size_t _samplesPerPixel;
            std::unique_ptr<Scene> _scene;
            std::unique_ptr<IRenderer> _renderer;
            std::map<std::string, std::shared_ptr<IMaterial>> _materials;

            /**
             * @brief Parse the camera section
             * @param root The config root
            */
            void _parseCamera(const libconfig::Setting &root);

            /**
             * @brief Parse the renderer section
             * @param root The config root
            */
            void _parseRenderer(const libconfig::Setting &root);

            /**
             * @brief Parse the materials section
             * @param root The config root
            */
            void _parseMaterials(const libconfig::Setting &root);

            /**
             * @brief Parse a material
             * @param setting The material setting
            */
            void _parseMaterial(const libconfig::Setting &setting);

            /**
             * @brief Parse the lights section
             * @param root The config root
            */
            void _parseLights(const libconfig::Setting &root);

            /**
             * @brief Parse a light
             * @param setting The light setting
            */
            void _parseLight(const libconfig::Setting &setting);

            /**
             * @brief Parse the objects section
             * @param root The config root
            */
            void _parseObjects(const libconfig::Setting &root);

            /**
             * @brief Parse a object
             * @param setting The object setting
            */
            void _parseObject(const libconfig::Setting &setting);

            /**
             * @brief Gets the value of a setting as a double even if it's an int
             * @param setting The setting to get the value from
             * @return The value as a double
             * @note libconfig sucks
            */
            double _getDouble(const libconfig::Setting &setting) const;

            /**
             * @brief Gets the value of a setting as a int even if it's a double
             * @param setting The setting to get the value from
             * @return The value as a int
             * @note libconfig sucks
            */
            int _getInt(const libconfig::Setting &setting) const;

        public:
            /**
             * @brief Construct a new Parser object
             * @param loader The plugin loader to use
             */
            Parser(PluginLoader *loader);

            /**
             * @brief Destroy the Parser object
             */
            ~Parser();

            /**
             * @brief Parse a file
             * @param path The path to the file to parse
             */
            void parse(const std::string &path);

            /**
             * @brief Get the image width
             * @return The image width
             */
            std::size_t getImageWidth() const;

            /**
             * @brief Get the image height
             * @return The image height
             */
            std::size_t getImageHeight() const;

            /**
             * @brief Get the scene
             * @return The scene
             */
            std::unique_ptr<Scene> getScene();

            /**
             * @brief Get the renderer
             * @return The renderer
             */
            std::unique_ptr<IRenderer> getRenderer();

            /**
             * @brief Get the samples per pixel
             * @return The samples per pixel
             */
            std::size_t getSamplesPerPixel() const;
    };
}
