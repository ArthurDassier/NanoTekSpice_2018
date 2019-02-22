/*
** EPITECH PROJECT, 2019
** tests_Components_4071.cpp
** File description:
** tests_4071
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "IComponent.hpp"
#include "Component_4071.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Input.hpp"

Test(tests_Component_4071, test_check_construction)
{
    Component_4071 test("test");

    cr_assert_eq(test.getName(), "test");
    cr_assert_eq(test.getType(), "4071");
}

Test(tests_Component_4071, test_check_input_return_true)
{
    Component_4071 test("test");

    cr_assert_eq(test.check_input(1), true);
    cr_assert_eq(test.check_input(2), true);
    cr_assert_eq(test.check_input(5), true);
    cr_assert_eq(test.check_input(6), true);
    cr_assert_eq(test.check_input(8), true);
    cr_assert_eq(test.check_input(9), true);
    cr_assert_eq(test.check_input(12), true);
    cr_assert_eq(test.check_input(13), true);
}

Test(tests_Component_4071, test_check_output_return_true)
{
    Component_4071 test("test");

    cr_assert_eq(test.check_output(3), true);
    cr_assert_eq(test.check_output(4), true);
    cr_assert_eq(test.check_output(10), true);
    cr_assert_eq(test.check_output(11), true);
}

Test(tests_Component_4071, test_check_input_return_false)
{
    Component_4071 test("test");

    cr_assert_eq(test.check_input(10), false);
    cr_assert_eq(test.check_input(11), false);
    cr_assert_eq(test.check_input(33), false);
    cr_assert_eq(test.check_input(102), false);
}

Test(tests_Component_4071, test_check_output_return_false)
{
    Component_4071 test("test");

    cr_assert_eq(test.check_output(1), false);
    cr_assert_eq(test.check_output(2), false);
    cr_assert_eq(test.check_output(33), false);
    cr_assert_eq(test.check_output(102), false);
}

Test(tests_Component_4071, test_truth_table)
{
    Component_4071 test("test");
    True tru("tru");
    False fals("fals");
    Input undef("undef");

    cr_assert_eq(test.compute(3), nts::UNDEFINED);
    cr_assert_eq(test.compute(300), nts::UNDEFINED);
    test.setLink(1, tru, 1);
    test.setLink(2, tru, 1);
    cr_assert_eq(test.compute(3), nts::TRUE);
    test.setLink(5, fals, 1);
    test.setLink(6, tru, 1);
    cr_assert_eq(test.compute(4), nts::TRUE);
    test.setLink(9, fals, 1);
    test.setLink(8, fals, 1);
    cr_assert_eq(test.compute(10), nts::FALSE);
    test.setLink(9, undef, 1);
    cr_assert_eq(test.compute(10), nts::UNDEFINED);
    test.setLink(8, tru, 1);
    cr_assert_eq(test.compute(10), nts::TRUE);
}
