/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** ScalarList
*/

#pragma once

#include <cstddef>
#include <iostream>
#include <array>

namespace Math {
    template<std::size_t N>
    class ScalarList {
        protected:
            /**
             * @brief ScalarList constructor
             */
            ScalarList()
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] = 0;
                }
            }

            /**
             * @brief ScalarList constructor with arguments
            */
            ScalarList(const double (&args)[N])
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] = args[c];
                }
            }

            /**
             * @brief ScalarList copy constructor
            */
            ScalarList(const ScalarList &other) = default;

            /**
             * @brief ScalarList move constructor
            */
            ScalarList(ScalarList &&other)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] = other._co[c];
                    other._co[c] = 0;
                }
            }

            /**
             * @brief ScalarList destructor
            */
            ~ScalarList() = default;

        public:
            double &operator[](std::size_t index)
            {
                return this->_co[index];
            }
            const double &operator[](std::size_t index) const
            {
                return this->_co[index];
            }

            ScalarList &operator=(const ScalarList &other)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] = other._co[c];
                }
                return *this;
            }
            ScalarList &operator=(ScalarList &&other)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] = other._co[c];
                    other._co[c] = 0;
                }
                return *this;
            }

            ScalarList operator+(const ScalarList &other)
            {
                ScalarList result;

                for (std::size_t c = 0; c < N; c++) {
                    result._co[c] = this->_co[c] + other._co[c];
                }
                return result;
            }
            ScalarList &operator+=(const ScalarList &other)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] += other._co[c];
                }
                return *this;
            }
            ScalarList operator-(const ScalarList &other)
            {
                ScalarList result;

                for (std::size_t c = 0; c < N; c++) {
                    result._co[c] = this->_co[c] - other._co[c];
                }
                return result;
            }
            ScalarList &operator-=(const ScalarList &other)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] -= other._co[c];
                }
                return *this;
            }
            ScalarList operator*(const ScalarList &other)
            {
                ScalarList result;

                for (std::size_t c = 0; c < N; c++) {
                    result._co[c] = this->_co[c] * other._co[c];
                }
                return result;
            }
            ScalarList &operator*=(const ScalarList &other)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] *= other._co[c];
                }
                return *this;
            }
            ScalarList operator/(const ScalarList &other)
            {
                ScalarList result;

                for (std::size_t c = 0; c < N; c++) {
                    result._co[c] = this->_co[c] / other._co[c];
                }
                return result;
            }
            ScalarList &operator/=(const ScalarList &other)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] /= other._co[c];
                }
                return *this;
            }
        protected:
            std::array<double, N> _co;
    };

    template<std::size_t N>
    std::ostream &operator<<(std::ostream &os, const ScalarList<N> &object)
    {
        os << "ScalarList(";
        for (std::size_t c = 0; c < N; c++) {
            os << object[c];
            if (c != N - 1) {
                os << ", ";
            }
        }
        os << ")";
        return os;
    }
}
