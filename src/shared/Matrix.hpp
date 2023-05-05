/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Matrix
*/

#pragma once

#include <cstddef>
#include <iostream>
#include <vector>

#include "Point.hpp"
#include "Vector.hpp"

namespace Math {
    class Matrix {
        protected:
            std::size_t rows, cols;
            std::array<std::array<double, 4>, 4> _matrix;

        public:
            Matrix(std::size_t rows_, std::size_t cols_);
            Matrix(std::initializer_list<std::initializer_list<double>> list);
            Matrix(const Matrix &other);
            Matrix(Matrix &&other);

            ~Matrix() = default;

            /**
             * @brief Get the number of rows of the matrix
             * @return The number of rows
            */
            std::size_t getRows() const noexcept;

            /**
             * @brief Get the number of columns of the matrix
             * @return The number of columns
            */
            std::size_t getCols() const noexcept;

            /**
             * @brief Get the value at the given position
             * @param i The row index
             * @param j The column index
             * @return The value at the given position
            */
            double &operator()(std::size_t i, std::size_t j);

            /**
             * @brief Get a reference to the value at the given position
             * @param i The row index
             * @param j The column index
             * @return The value at the given position
            */
            const double &operator()(std::size_t i, std::size_t j) const;

            Matrix operator+(const Matrix &other);

            Matrix &operator+=(const Matrix &other);
            Matrix operator-(const Matrix &other) const;
            Matrix &operator-=(const Matrix &other);
            Matrix operator*(const Matrix &other) const;
            Matrix &operator*=(const Matrix &other);

            Matrix operator*(double scalar) const;
            Matrix &operator*=(double scalar);
            Matrix operator/(double scalar) const;
            Matrix &operator/=(double scalar);

            Math::Point<3> operator*(const Math::Point<3> &point) const;
            Math::Vector<3> operator*(const Math::Vector<3> &vector) const;
            Math::Point<4> operator*(const Math::Point<4> &point) const;
            Math::Vector<4> operator*(const Math::Vector<4> &vector) const;

            Matrix &operator=(const Matrix &other);
            Matrix &operator=(Matrix &&other);

            /**
             * @brief Transpose the matrix
             * @return The transposed matrix
            */
            Matrix transpose() const;

            /**
             * @brief Get the determinant of the matrix
             * @return The determinant of the matrix
            */
            double determinant() const;

            /**
             * @brief Get the cofactor of the matrix
             * @return The cofactor of the matrix
            */
            Matrix cofactor() const;

            /**
             * @brief Get a cofactor value of the matrix
             * @param row The row of the cofactor
             * @param col The column of the cofactor
             * @return The cofactor value
            */
            double cofactor(std::size_t row, std::size_t col) const;

            /**
             * @brief Get the inverse of the matrix
             * @return The inverse of the matrix
            */
            Matrix inverse() const;
    };

    /**
     * @brief Print the matrix to the given output stream
     * @param os The output stream
     * @param matrix The matrix to print
     * @return The output stream
    */
    std::ostream &operator<<(std::ostream &os, const Math::Matrix &matrix);
}
