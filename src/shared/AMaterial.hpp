/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** AMaterial
*/

#pragma once

#include "IMaterial.hpp"

namespace RayTracer {
    class AMaterial : public IMaterial {
        public:
            /**
             * @brief AMaterial constructor
            */
            AMaterial() = default;
            /**
             * @brief AMaterial destructor
            */
            virtual ~AMaterial() = default;

            /**
             * @brief Get the color of the material at a given point
             * @param ray The ray that hit the material
             * @param hit The hit information
             * @return The color of the material at the given point
            */
            virtual Color getPointColor(const Ray &ray, const RayHit &hit) const = 0;

            /**
             * @brief Get the scatter of the material at a given point
             * @param ray The ray that hit the material
             * @param hit The hit information
             * @param scatter A reference to the scatter to fill
             * @return true if the material got scattered, false otherwise
            */
            virtual bool getScatter(const Ray &ray, const RayHit &hit, Scatter &scatter) const = 0;

            /**
             * @brief Get the color of the material
             * @return The color of the material
            */
            virtual Color getColor() const noexcept;

            /**
             * @brief Set the color of the material
             * @param color The new color of the material
            */
            virtual void setColor(const Color &color) noexcept;

            /**
             * @brief Get the albedo of the material
             * @return The albedo of the material
             * @note The albedo is used for metal materials
            */
            virtual double getAlbedo() const noexcept;

            /**
             * @brief Set the albedo of the material
             * @param albedo The new albedo of the material
             * @note The albedo is used for metal materials
             * @note The albedo should be a value between 0 and 1, this is why the function is not noexcept
            */
            virtual void setAlbedo(double albedo);

            /**
             * @brief Get the fuzziness of the material
             * @return The fuzziness of the material
             * @note The fuzziness is used for metal materials
            */
            virtual double getFuzziness() const noexcept;

            /**
             * @brief Set the fuzziness of the material
             * @param fuzziness The new fuzziness of the material
             * @note The fuzziness is used for metal materials
             * @note The fuzziness should be a value between 0 and 1, this is why the function is not noexcept
            */
            virtual void setFuzziness(double fuzziness);

            /**
             * @brief Get the refraction index of the material
             * @return The refraction index of the material
             * @note The refraction index is used for dielectric materials
            */
            virtual double getRefractionIndex() const noexcept;

            /**
             * @brief Set the refraction index of the material
             * @param refractionIndex The new refraction index of the material
             * @note The refraction index is used for dielectric materials
             * @note The refraction index should be a value greater than 1, this is why the function is not noexcept
            */
            virtual void setRefractionIndex(double refractionIndex);
    };
}
