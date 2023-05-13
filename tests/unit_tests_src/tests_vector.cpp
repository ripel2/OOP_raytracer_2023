/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** tests_vector
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Point.hpp"
#include "Vector.hpp"

static const double GLOBAL_PRECISION = 0.0000000001;

static void my_assert_double_eq(double a, double b)
{
    cr_assert_float_eq(a, b, GLOBAL_PRECISION);
}

Test(vector, creation) {
    Math::Vector<1> v1;
    Math::Vector<2> v2;
    Math::Vector<3> v3;

    my_assert_double_eq(v1[0], 0);
    my_assert_double_eq(v2[0], 0);
    my_assert_double_eq(v2[1], 0);
    my_assert_double_eq(v3[0], 0);
    my_assert_double_eq(v3[1], 0);
    my_assert_double_eq(v3[2], 0);
}

Test(vector, creation_args) {
    Math::Vector<2> v2({1, 2});

    my_assert_double_eq(v2[0], 1);
    my_assert_double_eq(v2[1], 2);
}

Test(vector, copy_constructor) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_copy{v3};

    my_assert_double_eq(v3_copy[0], 1);
    my_assert_double_eq(v3_copy[1], 2);
    my_assert_double_eq(v3_copy[2], 3);
}

Test(vector, move_constructor) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_move{std::move(v3)};

    my_assert_double_eq(v3_move[0], 1);
    my_assert_double_eq(v3_move[1], 2);
    my_assert_double_eq(v3_move[2], 3);
    my_assert_double_eq(v3[0], 0);
    my_assert_double_eq(v3[1], 0);
    my_assert_double_eq(v3[2], 0);
}

Test(vector, copy_assignment) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_copy;

    v3_copy = v3;
    my_assert_double_eq(v3_copy[0], 1);
    my_assert_double_eq(v3_copy[1], 2);
    my_assert_double_eq(v3_copy[2], 3);
}

Test(vector, move_assignment) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_move;

    v3_move = std::move(v3);
    my_assert_double_eq(v3_move[0], 1);
    my_assert_double_eq(v3_move[1], 2);
    my_assert_double_eq(v3_move[2], 3);
    my_assert_double_eq(v3[0], 0);
    my_assert_double_eq(v3[1], 0);
    my_assert_double_eq(v3[2], 0);
}

Test(vector, addition_vector) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_add({4, 5, 6});

    auto v3_res = v3 + v3_add;
    my_assert_double_eq(v3_res[0], 5);
    my_assert_double_eq(v3_res[1], 7);
    my_assert_double_eq(v3_res[2], 9);
}

Test(vector, substraction_vector) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_sub({4, 5, 6});

    auto v3_res = v3 - v3_sub;
    my_assert_double_eq(v3_res[0], -3);
    my_assert_double_eq(v3_res[1], -3);
    my_assert_double_eq(v3_res[2], -3);
}

Test(vector, addition) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_add({4, 5, 6});

    v3 += v3_add;
    my_assert_double_eq(v3[0], 5);
    my_assert_double_eq(v3[1], 7);
    my_assert_double_eq(v3[2], 9);
}

Test(vector, substraction) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_sub({4, 5, 6});

    v3 -= v3_sub;
    my_assert_double_eq(v3[0], -3);
    my_assert_double_eq(v3[1], -3);
    my_assert_double_eq(v3[2], -3);
}

// Results got calculated from symbolab.com

Test(vector, length) {
    Math::Vector<3> v3({1, 2, 3});

    my_assert_double_eq(v3.length(), 3.7416573867739413);
}

Test(vector, length_test_2) {
    Math::Vector<3> v3({0, 0, 0});

    my_assert_double_eq(v3.length(), 0);
}

Test(vector, length_test_3) {
    Math::Vector<3> v3({1, 0, 0});

    my_assert_double_eq(v3.length(), 1);
}

Test(vector, length_test_4) {
    Math::Vector<3> v3({0, 1, 0});

    my_assert_double_eq(v3.length(), 1);
}

Test(vector, length_test_5) {
    Math::Vector<3> v3({0, 0, 1});

    my_assert_double_eq(v3.length(), 1);
}

Test(vector, dot_product) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_dot({4, 5, 6});

    my_assert_double_eq(v3.dot(v3_dot), 32);
}

Test(vector, dot_product_2) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_dot({0, 0, 0});

    my_assert_double_eq(v3.dot(v3_dot), 0);
}

Test(vector, dot_product_3) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_dot({1, 5, 7});

    my_assert_double_eq(v3.dot(v3_dot), 32);
}

Test(vector, dot_product_4) {
    Math::Vector<3> v3({7, 2, 1});
    Math::Vector<3> v3_dot({1, 5, 2});

    my_assert_double_eq(v3.dot(v3_dot), 19);
}

Test(vector, dot_product_5) {
    Math::Vector<3> v3({0, 0, 0});
    Math::Vector<3> v3_dot({1, 2, 3});

    my_assert_double_eq(v3.dot(v3_dot), 0);
}

Test(vector, dot_product_6) {
    Math::Vector<3> v3({0, 0, 0});
    Math::Vector<3> v3_dot({0, 0, 0});

    my_assert_double_eq(v3.dot(v3_dot), 0);
}

Test(vector, projection_1) {
    Math::Vector<3> v3({4, 5, 6});
    Math::Vector<3> v3_onto({1, 2, 3});
    auto v3_res = v3.projection(v3_onto);

    my_assert_double_eq(v3_res[0], double(128)/double(77));
    my_assert_double_eq(v3_res[1], double(160)/double(77));
    my_assert_double_eq(v3_res[2], double(192)/double(77));
}

Test(vector, projection_2) {
    Math::Vector<3> v3({1, 2, 3});
    Math::Vector<3> v3_onto({4, 5, 6});
    auto v3_res = v3.projection(v3_onto);

    my_assert_double_eq(v3_res[0], double(16)/double(7));
    my_assert_double_eq(v3_res[1], double(32)/double(7));
    my_assert_double_eq(v3_res[2], double(48)/double(7));
}

Test(vector, projection_3) {
    Math::Vector<3> v3({4, 5, 6});
    Math::Vector<3> v3_onto;
    auto v3_res = v3.projection(v3_onto);

    my_assert_double_eq(v3_res[0], 0);
    my_assert_double_eq(v3_res[1], 0);
    my_assert_double_eq(v3_res[2], 0);
}

Test(vector, projection_4) {
    Math::Vector<3> v3({1, 1, 1});
    Math::Vector<3> v3_onto({6, 6, 7});
    auto v3_res = v3.projection(v3_onto);

    my_assert_double_eq(v3_res[0], double(19)/double(3));
    my_assert_double_eq(v3_res[1], double(19)/double(3));
    my_assert_double_eq(v3_res[2], double(19)/double(3));
}

Test(vector, projection_5) {
    Math::Vector<3> v3({6, 6, 7});
    Math::Vector<3> v3_onto({1, 1, 1});
    auto v3_res = v3.projection(v3_onto);

    my_assert_double_eq(v3_res[0], double(114)/double(121));
    my_assert_double_eq(v3_res[1], double(114)/double(121));
    my_assert_double_eq(v3_res[2], double(133)/double(121));
}

Test(vector, normalize) {
    Math::Vector<3> v3({1, 2, 3});
    v3.normalize();

    my_assert_double_eq(v3[0], double(1)/double(3.7416573867739413));
    my_assert_double_eq(v3[1], double(2)/double(3.7416573867739413));
    my_assert_double_eq(v3[2], double(3)/double(3.7416573867739413));
}

Test(vector, normalize_2) {
    Math::Vector<3> v3({1, 0, 0});
    v3.normalize();

    my_assert_double_eq(v3[0], 1);
    my_assert_double_eq(v3[1], 0);
    my_assert_double_eq(v3[2], 0);
}

Test(vector, normalize_3) {
    Math::Vector<3> v3({0, 1, 0});
    v3.normalize();

    my_assert_double_eq(v3[0], 0);
    my_assert_double_eq(v3[1], 1);
    my_assert_double_eq(v3[2], 0);
}

Test(vector, normalize_4) {
    Math::Vector<3> v3({0, 0, 1});
    v3.normalize();

    my_assert_double_eq(v3[0], 0);
    my_assert_double_eq(v3[1], 0);
    my_assert_double_eq(v3[2], 1);
}

Test(vector, magnitude) {
    Math::Vector<3> v3({1, 2, 3});

    my_assert_double_eq(v3.magnitude(), 3.7416573867739413);
}

Test(vector, magnitude_2) {
    Math::Vector<3> v3({1, 0, 0});

    my_assert_double_eq(v3.magnitude(), 1);
}

Test(vector, magnitude_3) {
    Math::Vector<3> v3({0, 1, 0});

    my_assert_double_eq(v3.magnitude(), 1);
}

Test(vector, magnitude_4) {
    Math::Vector<3> v3({0, 0, 1});

    my_assert_double_eq(v3.magnitude(), 1);
}

Test(vector, magnitude_5) {
    Math::Vector<3> v3({0, 0, 0});

    my_assert_double_eq(v3.magnitude(), 0);
}

Test(vector, magnitude_6) {
    Math::Vector<3> v3({1, 1, 1});

    my_assert_double_eq(v3.magnitude(), 1.7320508075688772);
}

Test(vector, magnitude_7) {
    Math::Vector<3> v3({-1, -1, -1});

    my_assert_double_eq(v3.magnitude(), 1.7320508075688772);
}

Test(vector, magnitude_8) {
    Math::Vector<3> v3({-1, 1, 1});

    my_assert_double_eq(v3.magnitude(), 1.7320508075688772);
}

Test(vector, unit) {
    Math::Vector<3> v3({1, 2, 3});
    v3.unit();

    my_assert_double_eq(v3[0], double(1)/double(3.7416573867739413));
    my_assert_double_eq(v3[1], double(2)/double(3.7416573867739413));
    my_assert_double_eq(v3[2], double(3)/double(3.7416573867739413));
}

Test(vector, unit_2) {
    Math::Vector<3> v3({1, 0, 0});
    v3.unit();

    my_assert_double_eq(v3[0], 1);
    my_assert_double_eq(v3[1], 0);
    my_assert_double_eq(v3[2], 0);
}

Test(vector, unit_3) {
    Math::Vector<3> v3({0, 1, 0});
    v3.unit();

    my_assert_double_eq(v3[0], 0);
    my_assert_double_eq(v3[1], 1);
    my_assert_double_eq(v3[2], 0);
}

Test(vector, unit_4) {
    Math::Vector<3> v3({0, 0, 1});
    v3.unit();

    my_assert_double_eq(v3[0], 0);
    my_assert_double_eq(v3[1], 0);
    my_assert_double_eq(v3[2], 1);
}

Test(vector, unit_5) {
    Math::Vector<3> v3({-6, -4, 2});
    v3.unit();

    my_assert_double_eq(v3[0], -0.8017837257372732);
    my_assert_double_eq(v3[1], -0.5345224838248488);
    my_assert_double_eq(v3[2], 0.2672612419124244);
}

Test(vector, unit_6) {
    Math::Vector<3> v3({4, 4, 2});
    // J'arrive en 4-4-2 dans un 4 4 noir
    v3.unit();

    my_assert_double_eq(v3[0], 0.6666666666666666);
    my_assert_double_eq(v3[1], 0.6666666666666666);
    my_assert_double_eq(v3[2], 0.3333333333333333);
}
