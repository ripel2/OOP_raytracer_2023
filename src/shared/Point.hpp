/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Point
*/

#pragma once

#include "ScalarList.hpp"
#include "Vector.hpp"

#include <cmath>
#include <ostream>

namespace Math {
    template<std::size_t N>
    class Point : public ScalarList<N> {
        public:

            /**
             * @brief Point constructor
             */
            Point()
                : ScalarList<N>()
            {
            }

            /**
             * @brief Point constructor with arguments
             */
            Point(const double (&args)[N])
                : ScalarList<N>(args)
            {
            }

            Point operator+(const Vector<N> &vector) const
            {
                Point<N> result;

                for (std::size_t c = 0; c < N; c++) {
                    result._co[c] = this->_co[c] + vector[c];
                }
                return result;
            }

            Point &operator+=(const Vector<N> &vector)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] += vector[c];
                }
                return *this;
            }

            Point operator-(const Vector<N> &vector) const
            {
                Point<N> result;

                for (std::size_t c = 0; c < N; c++) {
                    result._co[c] = this->_co[c] - vector[c];
                }
                return result;
            }

            Point &operator-=(const Vector<N> &vector)
            {
                for (std::size_t c = 0; c < N; c++) {
                    this->_co[c] -= vector[c];
                }
                return *this;
            }
    };

    template<std::size_t N>
    std::ostream &operator<<(std::ostream &os, const Point<N> &point)
    {
        os << "Point<" << N << ">(";
        for (std::size_t c = 0; c < N; c++) {
            os << point[c];
            if (c != N - 1)
                os << ", ";
        }
        os << ")";
        return os;
    }
}
