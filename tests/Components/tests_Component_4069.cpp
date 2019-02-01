/*
** EPITECH PROJECT, 2019
** tests_Components_4069.cpp
** File description:
** tests_4069
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "IComponent.hpp"
#include "Component_4069.hpp"
#include "True.hpp"
#include "False.hpp"

Test(tests_Component_4069, test_check_input_return_true)
{
    Component_4069 test("test");

    cr_assert_eq(test.check_input(1), true);
    cr_assert_eq(test.check_input(3), true);
    cr_assert_eq(test.check_input(5), true);
    cr_assert_eq(test.check_input(9), true);
    cr_assert_eq(test.check_input(11), true);
    cr_assert_eq(test.check_input(13), true);
}

Test(tests_Component_4069, test_check_output_return_true)
{
    Component_4069 test("test");

    cr_assert_eq(test.check_output(2), true);
    cr_assert_eq(test.check_output(4), true);
    cr_assert_eq(test.check_output(6), true);
    cr_assert_eq(test.check_output(8), true);
    cr_assert_eq(test.check_output(10), true);
    cr_assert_eq(test.check_output(12), true);
}

Test(tests_Component_4069, test_check_input_return_false)
{
    Component_4069 test("test");

    cr_assert_eq(test.check_input(10), false);
    cr_assert_eq(test.check_input(12), false);
    cr_assert_eq(test.check_input(33), false);
    cr_assert_eq(test.check_input(102), false);
}

Test(tests_Component_4069, test_check_output_return_false)
{
    Component_4069 test("test");

    cr_assert_eq(test.check_output(1), false);
    cr_assert_eq(test.check_output(3), false);
    cr_assert_eq(test.check_output(33), false);
    cr_assert_eq(test.check_output(102), false);
}

Test(tests_Component_4069, test_truth_table)
{
    Component_4069 test("test");
    True tru("tru");
    False fals("fals");

    cr_assert_eq(test.compute(2), nts::UNDEFINED);
    test.setLink(1, tru, 1);
    cr_assert_eq(test.compute(2), nts::FALSE);
    test.setLink(3, fals, 1);
    cr_assert_eq(test.compute(4), nts::TRUE);
    test.setLink(9, fals, 1);
    cr_assert_eq(test.compute(8), nts::TRUE);
}
