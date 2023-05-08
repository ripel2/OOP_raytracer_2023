/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** Matrix
*/

#include "Matrix.hpp"

Math::Matrix::Matrix(std::size_t rows_, std::size_t cols_)
    : rows(rows_), cols(cols_), _matrix()
{
    if (rows > 4 || cols > 4) {
        throw std::invalid_argument("Matrix must be at most 4x4.");
    }
}

Math::Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list)
    : rows(list.size()), cols(list.begin()->size()), _matrix()
{
    std::size_t i = 0;
    for (auto row : list) {
        if (row.size() != cols) {
            throw std::invalid_argument("Matrix must be rectangular.");
        }
        std::size_t j = 0;
        for (auto val : row) {
            _matrix[i][j] = val;
            j++;
        }
        i++;
    }
}

Math::Matrix::Matrix(const Math::Matrix &other)
    : rows(other.rows), cols(other.cols), _matrix(other._matrix)
{
}

Math::Matrix::Matrix(Matrix &&other)
    : rows(other.rows), cols(other.cols), _matrix(std::move(other._matrix))
{
}

/**
 * @brief Get the number of rows of the matrix
 * @return The number of rows
*/
std::size_t Math::Matrix::getRows() const noexcept
{
    return this->rows;
}

/**
 * @brief Get the number of columns of the matrix
 * @return The number of columns
*/
std::size_t Math::Matrix::getCols() const noexcept
{
    return this->cols;
}

/**
 * @brief Get the value at the given position
 * @param i The row index
 * @param j The column index
 * @return The value at the given position
*/
double &Math::Matrix::operator()(std::size_t i, std::size_t j)
{
    return this->_matrix[i][j];
}

/**
 * @brief Get a reference to the value at the given position
 * @param i The row index
 * @param j The column index
 * @return The value at the given position
*/
const double &Math::Matrix::operator()(std::size_t i, std::size_t j) const
{
    return this->_matrix[i][j];
}

Math::Matrix Math::Matrix::operator+(const Math::Matrix &other)
{
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Matrix operator+ : Matrices must have the same dimensions.");
    }
    Matrix result(this->rows, this->cols);
    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            result._matrix[i][j] = this->_matrix[i][j] + other._matrix[i][j];
        }
    }
    return result;
}

Math::Matrix &Math::Matrix::operator+=(const Math::Matrix &other)
{
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Matrix operator+= : Matrices must have the same dimensions.");
    }
    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            this->_matrix[i][j] += other._matrix[i][j];
        }
    }
    return *this;
}

Math::Matrix Math::Matrix::operator-(const Math::Matrix &other) const
{
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Matrix operator- : Matrices must have the same dimensions.");
    }
    Matrix result(this->rows, this->cols);
    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            result._matrix[i][j] = this->_matrix[i][j] - other._matrix[i][j];
        }
    }
    return result;
}

Math::Matrix &Math::Matrix::operator-=(const Math::Matrix &other)
{
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Matrix operator-= : Matrices must have the same dimensions.");
    }
    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            this->_matrix[i][j] -= other._matrix[i][j];
        }
    }
    return *this;
}


Math::Matrix Math::Matrix::operator*(const Math::Matrix &other) const
{
    if (this->cols != other.rows) {
        throw std::invalid_argument("Matrix operator* : Matrices must have the same dimensions.");
    }
    Math::Matrix result(this->rows, other.cols);
    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < other.cols; j++) {
            for (std::size_t k = 0; k < this->cols; k++) {
                result._matrix[i][j] += this->_matrix[i][k] * other._matrix[k][j];
            }
        }
    }
    return result;
}

Math::Matrix &Math::Matrix::operator*=(const Math::Matrix &other)
{
    if (this->cols != other.rows) {
        throw std::invalid_argument("Matrix operator*= : Matrices must have the same dimensions.");
    }
    Math::Matrix result(this->rows, other.cols);
    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < other.cols; j++) {
            for (std::size_t k = 0; k < this->cols; k++) {
                result._matrix[i][j] += this->_matrix[i][k] * other._matrix[k][j];
            }
        }
    }
    this->_matrix = std::move(result._matrix);
    this->cols = other.cols;
    return *this;
}


Math::Matrix Math::Matrix::operator*(double scalar) const
{
    Math::Matrix result(this->rows, this->cols);
    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            result._matrix[i][j] = this->_matrix[i][j] * scalar;
        }
    }
    return result;
}

Math::Matrix &Math::Matrix::operator*=(double scalar)
{
    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            this->_matrix[i][j] *= scalar;
        }
    }
    return *this;
}


Math::Matrix Math::Matrix::operator/(double scalar) const
{
    if (scalar == 0) {
        throw std::invalid_argument("Matrix operator/ : Scalar must not be 0.");
    }
    Math::Matrix result(this->rows, this->cols);
    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            result._matrix[i][j] = this->_matrix[i][j] / scalar;
        }
    }
    return result;
}

Math::Matrix &Math::Matrix::operator/=(double scalar)
{
    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            this->_matrix[i][j] /= scalar;
        }
    }
    return *this;
}

Math::Matrix &Math::Matrix::operator=(const Math::Matrix &other)
{
    if (this != &other) {
        this->rows = other.rows;
        this->cols = other.cols;

        for (std::size_t i = 0; i < rows; i++) {
            for (std::size_t j = 0; j < cols; j++) {
                this->_matrix[i][j] = other._matrix[i][j];
            }
        }
    }
    return *this;
}

Math::Matrix &Math::Matrix::operator=(Matrix &&other)
{
    if (this != &other) {
        this->rows = other.rows;
        this->cols = other.cols;
        this->_matrix = std::move(other._matrix);
    }
    return *this;
}

/**
 * @brief Transpose the matrix
 * @return The transposed matrix
*/
Math::Matrix Math::Matrix::transpose() const
{
    Math::Matrix result(this->cols, this->rows);
    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            result._matrix[j][i] = this->_matrix[i][j];
        }
    }
    return result;
}

/**
 * @brief Get the determinant of the matrix
 * @return The determinant of the matrix
*/
double Math::Matrix::determinant() const
{
    if (rows != cols) {
        throw std::invalid_argument("Matrix determinant : Matrix must be square.");
    }
    if (rows == 1) {
        return _matrix[0][0];
    }
    if (rows == 2) {
        return _matrix[0][0] * _matrix[1][1] - _matrix[0][1] * _matrix[1][0];
    }
    double det = 0;
    for (std::size_t i = 0; i < cols; i++) {
        Math::Matrix submatrix(rows - 1, cols - 1);
        for (std::size_t j = 1; j < rows; j++) {
            for (std::size_t k = 0; k < cols; k++) {
                if (k < i) {
                    submatrix(j - 1, k) = _matrix[j][k];
                } else if (k > i) {
                    submatrix(j - 1, k - 1) = _matrix[j][k];
                }
            }
        }
        double sign = (i % 2 == 0) ? 1 : -1;
        det += sign * _matrix[0][i] * submatrix.determinant();
    }
    return det;
}

/**
 * @brief Get the cofactor of the matrix
 * @return The cofactor of the matrix
*/
Math::Matrix Math::Matrix::cofactor() const
{
    if (rows != cols) {
        throw std::invalid_argument("Matrix cofactor : Matrix must be square.");
    }
    Math::Matrix result(rows, cols);
    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < cols; j++) {
            Math::Matrix submatrix(rows - 1, cols - 1);
            for (std::size_t k = 0; k < rows; k++) {
                for (std::size_t l = 0; l < cols; l++) {
                    if (k != i && l != j) {
                        submatrix((k < i) ? k : k - 1, (l < j) ? l : l - 1) = _matrix[k][l];
                    }
                }
            }
            double sign = ((i + j) % 2 == 0) ? 1 : -1;
            result(i, j) = sign * submatrix.determinant();
        }
    }
    return result;
}

/**
 * @brief Get a cofactor value of the matrix
 * @param row The row of the cofactor
 * @param col The column of the cofactor
 * @return The cofactor value
*/
double Math::Matrix::cofactor(std::size_t row, std::size_t col) const
{
    if (rows != cols) {
        throw std::invalid_argument("Matrix cofactor : Matrix must be square.");
    }
    if (row >= rows || col >= cols) {
        throw std::invalid_argument("Matrix cofactor : Row or column out of bounds.");
    }
    Math::Matrix submatrix(rows - 1, cols - 1);
    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < cols; j++) {
            if (i != row && j != col) {
                submatrix((i < row) ? i : i - 1, (j < col) ? j : j - 1) = _matrix[i][j];
            }
        }
    }
    double sign = ((row + col) % 2 == 0) ? 1 : -1;
    return sign * submatrix.determinant();
}

Math::Matrix Math::Matrix::inverse() const
{
    if (rows != cols) {
        throw std::invalid_argument("Matrix inverse: Matrix must be square.");
    }
    double det = determinant();
    if (det == 0) {
        throw std::invalid_argument("Matrix inverse: Matrix is singular.");
    }
    Math::Matrix cof = cofactor();
    cof = cof.transpose();
    cof /= det;
    return cof;
}

std::ostream &operator<<(std::ostream &os, const Math::Matrix &matrix)
{
    for (std::size_t i = 0; i < matrix.getRows(); i++) {
        for (std::size_t j = 0; j < matrix.getCols(); j++) {
            os << matrix(i, j) << " ";
        }
        os << std::endl;
    }
    return os;

}

Math::Vector<3> Math::Matrix::operator*(const Math::Vector<3> &vector) const
{
    if (cols < 3) {
        throw std::invalid_argument("Matrix * Vector<3> : Matrix must have at least 3 columns.");
    }
    Math::Vector<3> result;
    for (std::size_t i = 0; i < rows; i++) {
        result[i] = 0;
        for (std::size_t j = 0; j < cols; j++) {
            result[i] += _matrix[i][j] * vector[j];
        }
    }
    return result;
}

Math::Point<3> Math::Matrix::operator*(const Math::Point<3> &point) const
{
    if (cols < 3) {
        throw std::invalid_argument("Matrix * Point<3> : Matrix must have at least 3 columns.");
    }
    Math::Point<3> result;
    for (std::size_t i = 0; i < rows; i++) {
        result[i] = 0;
        for (std::size_t j = 0; j < cols; j++) {
            result[i] += _matrix[i][j] * point[j];
        }
    }
    return result;
}

Math::Vector<4> Math::Matrix::operator*(const Math::Vector<4> &vector) const
{
    if (cols < 4) {
        throw std::invalid_argument("Matrix * Vector<4> : Matrix must have at least 4 columns.");
    }
    Math::Vector<4> result;
    for (std::size_t i = 0; i < rows; i++) {
        result[i] = 0;
        for (std::size_t j = 0; j < cols; j++) {
            result[i] += _matrix[i][j] * vector[j];
        }
    }
    return result;
}

Math::Point<4> Math::Matrix::operator*(const Math::Point<4> &point) const
{
    if (cols < 4) {
        throw std::invalid_argument("Matrix * Point<4> : Matrix must have at least 4 columns.");
    }
    Math::Point<4> result;
    for (std::size_t i = 0; i < rows; i++) {
        result[i] = 0;
        for (std::size_t j = 0; j < cols; j++) {
            result[i] += _matrix[i][j] * point[j];
        }
    }
    return result;
}
