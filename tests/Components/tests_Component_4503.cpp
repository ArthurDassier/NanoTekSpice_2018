/*
** EPITECH PROJECT, 2019
** tests_Components_4503.cpp
** File description:
** tests_4503
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "IComponent.hpp"
#include "Component_4503.hpp"
#include "True.hpp"
#include "False.hpp"

Test(tests_Component_4503, test_check_input_return_true)
{
    Component_4503 test("test");

    cr_assert_eq(test.check_input(1), true);
    cr_assert_eq(test.check_input(2), true);
    cr_assert_eq(test.check_input(4), true);
    cr_assert_eq(test.check_input(6), true);
    cr_assert_eq(test.check_input(10), true);
    cr_assert_eq(test.check_input(12), true);
    cr_assert_eq(test.check_input(14), true);
    cr_assert_eq(test.check_input(15), true);
}

Test(tests_Component_4503, test_check_output_return_true)
{
    Component_4503 test("test");

    cr_assert_eq(test.check_output(3), true);
    cr_assert_eq(test.check_output(5), true);
    cr_assert_eq(test.check_output(7), true);
    cr_assert_eq(test.check_output(9), true);
    cr_assert_eq(test.check_output(11), true);
    cr_assert_eq(test.check_output(13), true);
}

Test(tests_Component_4503, test_check_input_return_false)
{
    Component_4503 test("test");

    cr_assert_eq(test.check_input(7), false);
    cr_assert_eq(test.check_input(11), false);
    cr_assert_eq(test.check_input(33), false);
    cr_assert_eq(test.check_input(102), false);
}

Test(tests_Component_4503, test_check_output_return_false)
{
    Component_4503 test("test");

    cr_assert_eq(test.check_output(1), false);
    cr_assert_eq(test.check_output(2), false);
    cr_assert_eq(test.check_output(33), false);
    cr_assert_eq(test.check_output(102), false);
}

Test(tests_Component_4503, test_truth_table)
{
    Component_4503 test("test");
    True tru("tru");
    False fals("fals");

    cr_assert_eq(test.compute(3), nts::UNDEFINED);
    test.setLink(1, tru, 1);
    test.setLink(2, tru, 1);
    cr_assert_eq(test.compute(3), nts::TRUE);
    test.setLink(1, fals, 1);
    test.setLink(4, tru, 1);
    cr_assert_eq(test.compute(5), nts::UNDEFINED);
    test.setLink(12, tru, 1);
    test.setLink(15, fals, 1);
    cr_assert_eq(test.compute(11), nts::TRUE);
}
