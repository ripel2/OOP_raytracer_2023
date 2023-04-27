/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Vector
*/

#pragma once

#include "ScalarList.hpp"

#include <cmath>
#include <ostream>

namespace Math {
    template<std::size_t N>
    class Point;

    template<std::size_t N>
    class Vector : public ScalarList<N> {
        public:
            Vector()
                : ScalarList<N>()
            {
            }

            Vector(const double (&args)[N])
                : ScalarList<N>(args)
            {
            }

            Vector(const Vector &other)
                : ScalarList<N>(other)
            {
            }
            Vector(Vector &&other)
                : ScalarList<N>(std::move(other))
            {
            }

            Vector(const Point<N> &point)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] = point[c];
                }
            }

            Vector &operator=(const Vector &other)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] = other._co[c];
                }
                return *this;
            }

            Vector &operator=(Vector &&other)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] = other._co[c];
                    other._co[c] = 0;
                }
                return *this;
            }

            Vector operator+(const Vector &vector) const
            {
                Vector<N> result;

                for (std::size_t c = 0; c < N; c++) {
                    result._co[c] = this->_co[c] + vector[c];
                }
                return result;
            }

            Vector &operator+=(const Vector &vector)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] += vector[c];
                }
                return *this;
            }

            Vector operator-(const Vector &vector) const
            {
                Vector<N> result;

                for (std::size_t c = 0; c < N; c++) {
                    result._co[c] = this->_co[c] - vector[c];
                }
                return result;
            }

            Vector &operator-=(const Vector &vector)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] -= vector[c];
                }
                return *this;
            }

            Vector operator*(const Vector &vector) const
            {
                Vector<N> result;

                for (std::size_t c = 0; c < N; c++) {
                    result._co[c] = this->_co[c] * vector[c];
                }
                return result;
            }

            Vector &operator*=(const Vector &vector)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] *= vector[c];
                }
                return *this;
            }

            Vector operator*(const double scalar) const
            {
                Vector<N> result;

                for (std::size_t c = 0; c < N; c++) {
                    result._co[c] = this->_co[c] * scalar;
                }
                return result;
            }

            Vector &operator*=(const double scalar)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] *= scalar;
                }
                return *this;
            }

            Vector operator/(const double scalar) const
            {
                Vector<N> result;

                for (std::size_t c = 0; c < N; c++) {
                    result._co[c] = this->_co[c] / scalar;
                }
                return result;
            }

            Vector &operator/=(const double scalar)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] /= scalar;
                }
                return *this;
            }

            /**
             * @brief Dot product of two vectors
             * @param vector The vector to dot with
             * @return The dot product
            */
            double dot(const Vector &vector) const
            {
                double res = 0;

                for (std::size_t c = 0; c < N; c++) {
                    res += this->_co[c] * vector[c];
                }
                return res;
            }

            /**
             * @brief Length of the vector (== magnitude)
             * @return The length of the vector
             * @note This is the same as magnitude()
            */
            double length() const
            {
                return std::sqrt(dot(*this));
            }

            /**
             * @brief Length squared of the vector
             * @return The length squared of the vector
            */
            double lengthSquared() const
            {
                return dot(*this);
            }

            /**
             * @brief Magnitude of the vector (== length)
             * @return The magnitude of the vector
             * @note This is the same as length()
            */
            double magnitude() const
            {
                return length();
            }

            /**
             * @brief Projection of the vector on another vector
             * @param vector2 The vector to project on
             * @return The projection of the vector2 on the current vector
            */
            Vector projection(const Vector &vector2) const
            {
                return *this * (vector2.dot(*this) / (pow(magnitude(), 2)));
            }

            /**
             * @brief Normalizes the vector
            */
            void normalize()
            {
                *this /= magnitude();
            }

            /**
             * @brief Returns the normalized vector
             * @return The normalized vector
            */
            Vector getNormalized() const
            {
                return *this / magnitude();
            }

            /**
             * @brief Normalizes the vector
            */
            void unit()
            {
                normalize();
            }

            /**
             * @brief Cross product of two vectors
             * @param vector The vector to cross with
             * @return The cross product
            */
            Vector cross(const Vector &vector) const
            {
                Vector<N> result;

                for (std::size_t c = 0; c < N; c++) {
                    result[c] = this->_co[(c + 1) % N] * vector[(c + 2) % N] -
                                this->_co[(c + 2) % N] * vector[(c + 1) % N];
                }
                return result;
            }
    };

    template<std::size_t N>
    std::ostream &operator<<(std::ostream &os, const Vector<N> &vector)
    {
        os << "Vector<" << N << ">(";
        for (std::size_t c = 0; c < N; c++) {
            os << vector[c];
            if (c != N - 1)
                os << ", ";
        }
        os << ")";
        return os;
    }
}
