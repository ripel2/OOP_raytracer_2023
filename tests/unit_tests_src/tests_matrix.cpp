/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** tests_matrix
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Point.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

static const double GLOBAL_PRECISION = 0.0000000001;

static void my_assert_double_eq(double a, double b)
{
    cr_assert_float_eq(a, b, GLOBAL_PRECISION);
}

Test(matrix, creation) {
    Math::Matrix m1(1, 1);
    Math::Matrix m2(2, 2);
    Math::Matrix m3(3, 3);

    my_assert_double_eq(m1(0, 0), 0);
    my_assert_double_eq(m2(0, 0), 0);
    my_assert_double_eq(m2(0, 1), 0);
    my_assert_double_eq(m2(1, 0), 0);
    my_assert_double_eq(m2(1, 1), 0);
    my_assert_double_eq(m3(0, 0), 0);
    my_assert_double_eq(m3(0, 1), 0);
    my_assert_double_eq(m3(0, 2), 0);
    my_assert_double_eq(m3(1, 0), 0);
    my_assert_double_eq(m3(1, 1), 0);
    my_assert_double_eq(m3(1, 2), 0);
    my_assert_double_eq(m3(2, 0), 0);
    my_assert_double_eq(m3(2, 1), 0);
    my_assert_double_eq(m3(2, 2), 0);
}

Test(matrix, creation_args) {
    Math::Matrix m2({{1, 2}, {3, 4}});

    my_assert_double_eq(m2(0, 0), 1);
    my_assert_double_eq(m2(0, 1), 2);
    my_assert_double_eq(m2(1, 0), 3);
    my_assert_double_eq(m2(1, 1), 4);
}

Test(matrix, copy_constructor) {
    Math::Matrix m3({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m3_copy{m3};

    my_assert_double_eq(m3_copy(0, 0), 1);
    my_assert_double_eq(m3_copy(0, 1), 2);
    my_assert_double_eq(m3_copy(0, 2), 3);
    my_assert_double_eq(m3_copy(1, 0), 4);
    my_assert_double_eq(m3_copy(1, 1), 5);
    my_assert_double_eq(m3_copy(1, 2), 6);
    my_assert_double_eq(m3_copy(2, 0), 7);
    my_assert_double_eq(m3_copy(2, 1), 8);
    my_assert_double_eq(m3_copy(2, 2), 9);
}

Test(matrix, copy_operator) {
    Math::Matrix m3({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m3_copy = m3;

    my_assert_double_eq(m3_copy(0, 0), 1);
    my_assert_double_eq(m3_copy(0, 1), 2);
    my_assert_double_eq(m3_copy(0, 2), 3);
    my_assert_double_eq(m3_copy(1, 0), 4);
    my_assert_double_eq(m3_copy(1, 1), 5);
    my_assert_double_eq(m3_copy(1, 2), 6);
    my_assert_double_eq(m3_copy(2, 0), 7);
    my_assert_double_eq(m3_copy(2, 1), 8);
    my_assert_double_eq(m3_copy(2, 2), 9);
}

// Move constructor will move the std::vector so we don't check for the other values
Test(matrix, move_constructor) {
    Math::Matrix m3({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m3_copy{std::move(m3)};

    my_assert_double_eq(m3_copy(0, 0), 1);
    my_assert_double_eq(m3_copy(0, 1), 2);
    my_assert_double_eq(m3_copy(0, 2), 3);
    my_assert_double_eq(m3_copy(1, 0), 4);
    my_assert_double_eq(m3_copy(1, 1), 5);
    my_assert_double_eq(m3_copy(1, 2), 6);
    my_assert_double_eq(m3_copy(2, 0), 7);
    my_assert_double_eq(m3_copy(2, 1), 8);
    my_assert_double_eq(m3_copy(2, 2), 9);
}

Test(matrix, move_operator) {
    Math::Matrix m3({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m3_copy = std::move(m3);

    my_assert_double_eq(m3_copy(0, 0), 1);
    my_assert_double_eq(m3_copy(0, 1), 2);
    my_assert_double_eq(m3_copy(0, 2), 3);
    my_assert_double_eq(m3_copy(1, 0), 4);
    my_assert_double_eq(m3_copy(1, 1), 5);
    my_assert_double_eq(m3_copy(1, 2), 6);
    my_assert_double_eq(m3_copy(2, 0), 7);
    my_assert_double_eq(m3_copy(2, 1), 8);
    my_assert_double_eq(m3_copy(2, 2), 9);
}

Test(matrix, addition) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m3 = m1 + m2;

    my_assert_double_eq(m3(0, 0), 2);
    my_assert_double_eq(m3(0, 1), 4);
    my_assert_double_eq(m3(0, 2), 6);
    my_assert_double_eq(m3(1, 0), 8);
    my_assert_double_eq(m3(1, 1), 10);
    my_assert_double_eq(m3(1, 2), 12);
    my_assert_double_eq(m3(2, 0), 14);
    my_assert_double_eq(m3(2, 1), 16);
    my_assert_double_eq(m3(2, 2), 18);
}

Test(matrix, addition_2) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    m2 += m1;
    my_assert_double_eq(m2(0, 0), 2);
    my_assert_double_eq(m2(0, 1), 4);
    my_assert_double_eq(m2(0, 2), 6);
    my_assert_double_eq(m2(1, 0), 8);
    my_assert_double_eq(m2(1, 1), 10);
    my_assert_double_eq(m2(1, 2), 12);
    my_assert_double_eq(m2(2, 0), 14);
    my_assert_double_eq(m2(2, 1), 16);
    my_assert_double_eq(m2(2, 2), 18);
}

Test(matrix, subtraction) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m3 = m1 - m2;

    my_assert_double_eq(m3(0, 0), 0);
    my_assert_double_eq(m3(0, 1), 0);
    my_assert_double_eq(m3(0, 2), 0);
    my_assert_double_eq(m3(1, 0), 0);
    my_assert_double_eq(m3(1, 1), 0);
    my_assert_double_eq(m3(1, 2), 0);
    my_assert_double_eq(m3(2, 0), 0);
    my_assert_double_eq(m3(2, 1), 0);
    my_assert_double_eq(m3(2, 2), 0);
}

Test(matrix, subtraction_2) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    m2 -= m1;
    my_assert_double_eq(m2(0, 0), 0);
    my_assert_double_eq(m2(0, 1), 0);
    my_assert_double_eq(m2(0, 2), 0);
    my_assert_double_eq(m2(1, 0), 0);
    my_assert_double_eq(m2(1, 1), 0);
    my_assert_double_eq(m2(1, 2), 0);
    my_assert_double_eq(m2(2, 0), 0);
    my_assert_double_eq(m2(2, 1), 0);
    my_assert_double_eq(m2(2, 2), 0);
}

Test(matrix, multiplication) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m3 = m1 * m2;

    my_assert_double_eq(m3(0, 0), 30);
    my_assert_double_eq(m3(0, 1), 36);
    my_assert_double_eq(m3(0, 2), 42);
    my_assert_double_eq(m3(1, 0), 66);
    my_assert_double_eq(m3(1, 1), 81);
    my_assert_double_eq(m3(1, 2), 96);
    my_assert_double_eq(m3(2, 0), 102);
    my_assert_double_eq(m3(2, 1), 126);
    my_assert_double_eq(m3(2, 2), 150);
}

Test(matrix, multiplication_2) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    m2 *= m1;
    my_assert_double_eq(m2(0, 0), 30);
    my_assert_double_eq(m2(0, 1), 36);
    my_assert_double_eq(m2(0, 2), 42);
    my_assert_double_eq(m2(1, 0), 66);
    my_assert_double_eq(m2(1, 1), 81);
    my_assert_double_eq(m2(1, 2), 96);
    my_assert_double_eq(m2(2, 0), 102);
    my_assert_double_eq(m2(2, 1), 126);
    my_assert_double_eq(m2(2, 2), 150);
}

Test(matrix, multiplication_3) {
    Math::Matrix m1({{11, 3}, {7, 11}});
    Math::Matrix m2({{8, 0, 1}, {0, 3, 5}});
    Math::Matrix m3 = m1 * m2;

    my_assert_double_eq(m3(0, 0), 88);
    my_assert_double_eq(m3(0, 1), 9);
    my_assert_double_eq(m3(0, 2), 26);
    my_assert_double_eq(m3(1, 0), 56);
    my_assert_double_eq(m3(1, 1), 33);
    my_assert_double_eq(m3(1, 2), 62);
}

Test(matrix, multiplication_scalar) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m2 = m1 * 2;

    my_assert_double_eq(m2(0, 0), 2);
    my_assert_double_eq(m2(0, 1), 4);
    my_assert_double_eq(m2(0, 2), 6);
    my_assert_double_eq(m2(1, 0), 8);
    my_assert_double_eq(m2(1, 1), 10);
    my_assert_double_eq(m2(1, 2), 12);
    my_assert_double_eq(m2(2, 0), 14);
    my_assert_double_eq(m2(2, 1), 16);
    my_assert_double_eq(m2(2, 2), 18);
}

Test(matrix, division_scalar) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m2 = m1 / 2;

    my_assert_double_eq(m2(0, 0), 0.5);
    my_assert_double_eq(m2(0, 1), 1);
    my_assert_double_eq(m2(0, 2), 1.5);
    my_assert_double_eq(m2(1, 0), 2);
    my_assert_double_eq(m2(1, 1), 2.5);
    my_assert_double_eq(m2(1, 2), 3);
    my_assert_double_eq(m2(2, 0), 3.5);
    my_assert_double_eq(m2(2, 1), 4);
    my_assert_double_eq(m2(2, 2), 4.5);
}

Test(matrix, division_scalar_2) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    m1 /= 2;
    my_assert_double_eq(m1(0, 0), 0.5);
    my_assert_double_eq(m1(0, 1), 1);
    my_assert_double_eq(m1(0, 2), 1.5);
    my_assert_double_eq(m1(1, 0), 2);
    my_assert_double_eq(m1(1, 1), 2.5);
    my_assert_double_eq(m1(1, 2), 3);
    my_assert_double_eq(m1(2, 0), 3.5);
    my_assert_double_eq(m1(2, 1), 4);
    my_assert_double_eq(m1(2, 2), 4.5);
}

Test(matrix, transpose) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m2 = m1.transpose();

    my_assert_double_eq(m2(0, 0), 1);
    my_assert_double_eq(m2(0, 1), 4);
    my_assert_double_eq(m2(0, 2), 7);
    my_assert_double_eq(m2(1, 0), 2);
    my_assert_double_eq(m2(1, 1), 5);
    my_assert_double_eq(m2(1, 2), 8);
    my_assert_double_eq(m2(2, 0), 3);
    my_assert_double_eq(m2(2, 1), 6);
    my_assert_double_eq(m2(2, 2), 9);
}

Test(matrix, transpose_2) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}});
    Math::Matrix m2 = m1.transpose();

    my_assert_double_eq(m2(0, 0), 1);
    my_assert_double_eq(m2(0, 1), 4);
    my_assert_double_eq(m2(1, 0), 2);
    my_assert_double_eq(m2(1, 1), 5);
    my_assert_double_eq(m2(2, 0), 3);
    my_assert_double_eq(m2(2, 1), 6);
}

Test(matrix, transpose_3) {
    Math::Matrix m1({{1, 2}, {4, 5}, {7, 8}});
    Math::Matrix m2 = m1.transpose();

    my_assert_double_eq(m2(0, 0), 1);
    my_assert_double_eq(m2(0, 1), 4);
    my_assert_double_eq(m2(0, 2), 7);
    my_assert_double_eq(m2(1, 0), 2);
    my_assert_double_eq(m2(1, 1), 5);
    my_assert_double_eq(m2(1, 2), 8);
}

Test(matrix, transpose_4) {
    Math::Matrix m1({{1}, {4}, {7}});
    Math::Matrix m2 = m1.transpose();

    my_assert_double_eq(m2(0, 0), 1);
    my_assert_double_eq(m2(0, 1), 4);
    my_assert_double_eq(m2(0, 2), 7);
}

Test(matrix, transpose_5) {
    Math::Matrix m1({{1, 2, 3}});
    Math::Matrix m2 = m1.transpose();

    my_assert_double_eq(m2(0, 0), 1);
    my_assert_double_eq(m2(1, 0), 2);
    my_assert_double_eq(m2(2, 0), 3);
}

Test(matrix, determinant) {
    Math::Matrix m1({{1, 2, 3}, {3, 2, 1}, {2, 1, 3}});

    my_assert_double_eq(m1.determinant(), -12);
}

Test(matrix, determinant_2) {
    Math::Matrix m1({{7, 2, 3}, {3, 2, 1}, {2, 1, 4}});

    my_assert_double_eq(m1.determinant(), 26);
}

Test(matrix, determinant_3) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    my_assert_double_eq(m1.determinant(), 0);
}

Test(matrix, determinant_4) {
    Math::Matrix m1({{1, 2, 3}, {3, 2, 1}, {0, 0, 0}});

    my_assert_double_eq(m1.determinant(), 0);
}

Test(matrix, determinant_5) {
    Math::Matrix m1({{1, 2, 0}, {3, 2, 0}, {2, 1, 0}});

    my_assert_double_eq(m1.determinant(), 0);
}

Test(matrix, determinant_6) {
    Math::Matrix m1(3, 3);
    // Empty matrix 3x3

    my_assert_double_eq(m1.determinant(), 0);
}

Test(matrix, determinant_edge_case_1) {
    Math::Matrix m1({{1}});

    my_assert_double_eq(m1.determinant(), 1);
}

Test(matrix, determinant_edge_case_2) {
    Math::Matrix m1({{1, 2}, {3, 4}});

    my_assert_double_eq(m1.determinant(), -2);
}

Test(matrix, determinant_edge_case_3) {
    Math::Matrix m1(2, 2);
    // Empty matrix 2x2

    my_assert_double_eq(m1.determinant(), 0);
}

Test(matrix, inverse_1) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 2, 9}});
    Math::Matrix m2 = m1.inverse();

    my_assert_double_eq(m2(0, 0), (double)-11/(double)12);
    my_assert_double_eq(m2(0, 1), (double)1/(double)3);
    my_assert_double_eq(m2(0, 2), (double)1/(double)12);
    my_assert_double_eq(m2(1, 0), (double)-1/(double)6);
    my_assert_double_eq(m2(1, 1), (double)1/(double)3);
    my_assert_double_eq(m2(1, 2), (double)-1/(double)6);
    my_assert_double_eq(m2(2, 0), (double)3/(double)4);
    my_assert_double_eq(m2(2, 1), (double)-1/(double)3);
    my_assert_double_eq(m2(2, 2), (double)1/(double)12);
}

Test(matrix, inverse_2) {
    Math::Matrix m1({{1, 3}, {2, 8}});
    Math::Matrix m2 = m1.inverse();

    my_assert_double_eq(m2(0, 0), (double)4);
    my_assert_double_eq(m2(0, 1), (double)-3/(double)2);
    my_assert_double_eq(m2(1, 0), (double)-1);
    my_assert_double_eq(m2(1, 1), (double)1/(double)2);
}

Test(matrix, inverse_3) {
    Math::Matrix m1({{1, 1}, {0, 1}});
    Math::Matrix m2 = m1.inverse();

    my_assert_double_eq(m2(0, 0), (double)1);
    my_assert_double_eq(m2(0, 1), (double)-1);
    my_assert_double_eq(m2(1, 0), (double)0);
    my_assert_double_eq(m2(1, 1), (double)1);
}

Test(matrix, inverse_4) {
    Math::Matrix m1({{1, 0}, {0, 1}});
    Math::Matrix m2 = m1.inverse();

    my_assert_double_eq(m2(0, 0), (double)1);
    my_assert_double_eq(m2(0, 1), (double)0);
    my_assert_double_eq(m2(1, 0), (double)0);
    my_assert_double_eq(m2(1, 1), (double)1);
}

Test(matrix, inverse_5) {
    Math::Matrix m1({{0, 1, 2}, {3, 2, 1}, {4, 4, 2}});
    Math::Matrix m2 = m1.inverse();

    my_assert_double_eq(m2(0, 0), 0);
    my_assert_double_eq(m2(0, 1), (double)1);
    my_assert_double_eq(m2(0, 2), (double)-1/(double)2);
    my_assert_double_eq(m2(1, 0), (double)-1/(double)3);
    my_assert_double_eq(m2(1, 1), (double)-4/(double)3);
    my_assert_double_eq(m2(1, 2), (double)1);
    my_assert_double_eq(m2(2, 0), (double)2/(double)3);
    my_assert_double_eq(m2(2, 1), (double)2/(double)3);
    my_assert_double_eq(m2(2, 2), (double)-1/(double)2);
}

Test(matrix, cofactor) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Matrix m2 = m1.cofactor();

    my_assert_double_eq(m2(0, 0), -3);
    my_assert_double_eq(m2(0, 1), 6);
    my_assert_double_eq(m2(0, 2), -3);
    my_assert_double_eq(m2(1, 0), 6);
    my_assert_double_eq(m2(1, 1), -12);
    my_assert_double_eq(m2(1, 2), 6);
    my_assert_double_eq(m2(2, 0), -3);
    my_assert_double_eq(m2(2, 1), 6);
    my_assert_double_eq(m2(2, 2), -3);
}

Test(matrix, cofactor_values) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    my_assert_double_eq(m1.cofactor(0, 0), -3);
    my_assert_double_eq(m1.cofactor(0, 1), 6);
    my_assert_double_eq(m1.cofactor(0, 2), -3);
    my_assert_double_eq(m1.cofactor(1, 0), 6);
    my_assert_double_eq(m1.cofactor(1, 1), -12);
    my_assert_double_eq(m1.cofactor(1, 2), 6);
    my_assert_double_eq(m1.cofactor(2, 0), -3);
    my_assert_double_eq(m1.cofactor(2, 1), 6);
    my_assert_double_eq(m1.cofactor(2, 2), -3);
}

Test(matrix, cofactor_2) {
    Math::Matrix m1({{1, 2}, {3, 4}});
    Math::Matrix m2 = m1.cofactor();

    my_assert_double_eq(m2(0, 0), 4);
    my_assert_double_eq(m2(0, 1), -3);
    my_assert_double_eq(m2(1, 0), -2);
    my_assert_double_eq(m2(1, 1), 1);
}

Test(matrix, cofactor_values_2) {
    Math::Matrix m1({{1, 2}, {3, 4}});

    my_assert_double_eq(m1.cofactor(0, 0), 4);
    my_assert_double_eq(m1.cofactor(0, 1), -3);
    my_assert_double_eq(m1.cofactor(1, 0), -2);
    my_assert_double_eq(m1.cofactor(1, 1), 1);
}

Test(matrix, multiply_matrix_with_vector3) {
    Math::Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Math::Vector<3> v1({1, 2, 3});
    Math::Vector<3> v2 = m1 * v1;

    my_assert_double_eq(v2[0], 14);
    my_assert_double_eq(v2[1], 32);
    my_assert_double_eq(v2[2], 50);
}

Test(matrix, multiply_matrix_with_vector3_2) {
    Math::Matrix m1({{1, -1, 2}, {0, -3, 1}});
    Math::Vector<3> v1({2, 1, 0});

    my_assert_double_eq((m1 * v1)[0], 1);
    my_assert_double_eq((m1 * v1)[1], -3);
    my_assert_double_eq((m1 * v1)[2], 0.0);
}

Test(matrix, multiply_matrix_with_vector3_3) {
    Math::Matrix m1({{4, 5, 6}});
    Math::Vector<3> v1({0, 1, 0});

    my_assert_double_eq((m1 * v1)[0], 5);
    my_assert_double_eq((m1 * v1)[1], 0.0);
    my_assert_double_eq((m1 * v1)[2], 0.0);
}

Test(matrix, multiply_matrix_with_vector4) {
    Math::Matrix m1({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 2}, {3, 4, 5, 6}});
    Math::Vector<4> v1({1, 2, 3, 4});
    Math::Vector<4> v2 = m1 * v1;

    my_assert_double_eq(v2[0], 30);
    my_assert_double_eq(v2[1], 70);
    my_assert_double_eq(v2[2], 20);
    my_assert_double_eq(v2[3], 50);
}

Test(matrix, multiply_matrix_with_vector4_2) {
    Math::Matrix m1({{1, 0, 2, 0}, {0, 3, 0, 4}, {0, 0, 5, 0}, {6, 0, 0, 7}});
    Math::Vector<4> v1({2, 5, 1, 8});

    my_assert_double_eq((m1 * v1)[0], 4);
    my_assert_double_eq((m1 * v1)[1], 47);
    my_assert_double_eq((m1 * v1)[2], 5);
    my_assert_double_eq((m1 * v1)[3], 68);
}

Test(matrix, multiply_matrix_with_vector4_3) {
    Math::Matrix m1({{1, 0, 0, 0}, {0, cos(45), -sin(45), 0}, {0, sin(45), cos(45), 0}, {0, 0, 0, 1}});
    Math::Vector<4> v1({1, 2, 3, 4});

    my_assert_double_eq((m1 * v1)[0], 1);
    my_assert_double_eq((m1 * v1)[1], 2 * cos(45) - 3 * sin(45));
    my_assert_double_eq((m1 * v1)[2], 2 * sin(45) + 3 * cos(45));
    my_assert_double_eq((m1 * v1)[3], 4);
}

Test(matrix, multiply_matrix_with_vector4_4) {
    Math::Matrix m1({{1, 0, 0, 2}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});
    Math::Vector<4> v1({1, 1, 1, 1});

    my_assert_double_eq((m1 * v1)[0], 3);
    my_assert_double_eq((m1 * v1)[1], 1);
    my_assert_double_eq((m1 * v1)[2], 1);
    my_assert_double_eq((m1 * v1)[3], 1);
}
