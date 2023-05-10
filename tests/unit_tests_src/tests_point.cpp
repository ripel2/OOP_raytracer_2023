/*
** EPITECH PROJECT, 2023
** bsraytracer [WSL: Ubuntu]
** File description:
** tests_point
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Point.hpp"
#include "Vector.hpp"

Test(point, creation) {
    Math::Point<1> p1;
    Math::Point<2> p2;
    Math::Point<3> p3;

    cr_assert_eq(p1[0], 0);
    cr_assert_eq(p2[0], 0);
    cr_assert_eq(p2[1], 0);
    cr_assert_eq(p3[0], 0);
    cr_assert_eq(p3[1], 0);
    cr_assert_eq(p3[2], 0);
}

Test(point, creation_args) {
    Math::Point<2> p2({1, 2});

    cr_assert_eq(p2[0], 1);
    cr_assert_eq(p2[1], 2);
}

Test(point, copy_constructor) {
    Math::Point<3> p3({1, 2, 3});
    Math::Point<3> p3_copy{p3};

    cr_assert_eq(p3_copy[0], 1);
    cr_assert_eq(p3_copy[1], 2);
    cr_assert_eq(p3_copy[2], 3);
}

Test(point, move_constructor) {
    Math::Point<3> p3({1, 2, 3});
    Math::Point<3> p3_move{std::move(p3)};

    cr_assert_eq(p3_move[0], 1);
    cr_assert_eq(p3_move[1], 2);
    cr_assert_eq(p3_move[2], 3);
    cr_assert_eq(p3[0], 0);
    cr_assert_eq(p3[1], 0);
    cr_assert_eq(p3[2], 0);
}

Test(point, copy_assignment) {
    Math::Point<3> p3({1, 2, 3});
    Math::Point<3> p3_copy;

    p3_copy = p3;
    cr_assert_eq(p3_copy[0], 1);
    cr_assert_eq(p3_copy[1], 2);
    cr_assert_eq(p3_copy[2], 3);
}

Test(point, move_assignment) {
    Math::Point<3> p3({1, 2, 3});
    Math::Point<3> p3_move;

    p3_move = std::move(p3);
    cr_assert_eq(p3_move[0], 1);
    cr_assert_eq(p3_move[1], 2);
    cr_assert_eq(p3_move[2], 3);
    cr_assert_eq(p3[0], 0);
    cr_assert_eq(p3[1], 0);
    cr_assert_eq(p3[2], 0);
}

Test(point, add_operators) {
    Math::Point<3> p3({1, 2, 3});
    Math::Vector<3> v3({1, 2, 3});

    Math::Point<3> p3_add = p3 + v3;
    Math::Point<3> p3_add2 = p3;
    p3_add2 += v3;

    cr_assert_eq(p3_add[0], 2);
    cr_assert_eq(p3_add[1], 4);
    cr_assert_eq(p3_add[2], 6);
    cr_assert_eq(p3_add2[0], 2);
    cr_assert_eq(p3_add2[1], 4);
    cr_assert_eq(p3_add2[2], 6);
}

Test(point, sub_operators) {
    Math::Point<3> p3({1, 2, 3});
    Math::Vector<3> v3({1, 2, 3});

    Math::Point<3> p3_sub = p3 - v3;
    Math::Point<3> p3_sub2 = p3;
    p3_sub2 -= v3;

    cr_assert_eq(p3_sub[0], 0);
    cr_assert_eq(p3_sub[1], 0);
    cr_assert_eq(p3_sub[2], 0);
    cr_assert_eq(p3_sub2[0], 0);
    cr_assert_eq(p3_sub2[1], 0);
    cr_assert_eq(p3_sub2[2], 0);
}

