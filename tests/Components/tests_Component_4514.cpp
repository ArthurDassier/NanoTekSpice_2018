/*
** EPITECH PROJECT, 2019
** Tests
** File description:
** 4514
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "IComponent.hpp"
#include "Component_4514.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Input.hpp"

Test(tests_Component_4514, test_check_construction)
{
    Component_4514 test("test");

    cr_assert_eq(test.getName(), "test");
    cr_assert_eq(test.getType(), "4514");
}

Test(tests_Component_4514, test_check_input_return_true)
{
    Component_4514 test("test");

    cr_assert_eq(test.check_input(1), true);
    cr_assert_eq(test.check_input(2), true);
    cr_assert_eq(test.check_input(3), true);
    cr_assert_eq(test.check_input(21), true);
    cr_assert_eq(test.check_input(22), true);
    cr_assert_eq(test.check_input(23), true);
}

Test(tests_Component_4514, test_check_output_return_true)
{
    Component_4514 test("test");

    cr_assert_eq(test.check_output(4), true);
    cr_assert_eq(test.check_output(10), true);
    cr_assert_eq(test.check_output(13), true);
    cr_assert_eq(test.check_output(17), true);
}

Test(tests_Component_4514, test_check_input_return_false)
{
    Component_4514 test("test");

    cr_assert_eq(test.check_input(8), false);
    cr_assert_eq(test.check_input(4), false);
    cr_assert_eq(test.check_input(33), false);
    cr_assert_eq(test.check_input(102), false);
}

Test(tests_Component_4514, test_check_output_return_false)
{
    Component_4514 test("test");

    cr_assert_eq(test.check_output(1), false);
    cr_assert_eq(test.check_output(2), false);
    cr_assert_eq(test.check_output(33), false);
    cr_assert_eq(test.check_output(102), false);
}

Test(tests_Component_4514, test_truth_table)
{
    Component_4514 test("test");
    True tru("tru");
    False fals("fals");
    Input undef("undef");

    cr_assert_eq(test.compute(8), nts::UNDEFINED);
    cr_assert_eq(test.compute(300), nts::UNDEFINED);
    test.setLink(1, tru, 1);
    test.setLink(3, tru, 1);
    test.setLink(21, fals, 1);
    test.setLink(22, fals, 1);
    test.setLink(23, fals, 1);
    cr_assert_eq(test.compute(7), nts::TRUE);
    cr_assert_eq(test.compute(8), nts::UNDEFINED);
    test.setLink(23, tru, 1);
    cr_assert_eq(test.compute(7), nts::FALSE);
    test.setLink(23, undef, 1);
    cr_assert_eq(test.compute(7), nts::UNDEFINED);
}