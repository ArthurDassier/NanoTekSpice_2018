/*
** EPITECH PROJECT, 2019
** tests_Components_4008.cpp
** File description:
** tests_4008
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "IComponent.hpp"
#include "Component_4008.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Input.hpp"

Test(tests_Component_4008, test_check_construction)
{
    Component_4008 test("test");

    cr_assert_eq(test.getName(), "test");
    cr_assert_eq(test.getType(), "4008");
}

Test(tests_Component_4008, test_check_input_return_true)
{
    Component_4008 test("test");

    cr_assert_eq(test.check_input(1), true);
    cr_assert_eq(test.check_input(2), true);
    cr_assert_eq(test.check_input(3), true);
    cr_assert_eq(test.check_input(4), true);
    cr_assert_eq(test.check_input(5), true);
    cr_assert_eq(test.check_input(6), true);
    cr_assert_eq(test.check_input(7), true);
    cr_assert_eq(test.check_input(9), true);
    cr_assert_eq(test.check_input(15), true);
}

Test(tests_Component_4008, test_check_output_return_true)
{
    Component_4008 test("test");

    cr_assert_eq(test.check_output(10), true);
    cr_assert_eq(test.check_output(11), true);
    cr_assert_eq(test.check_output(12), true);
    cr_assert_eq(test.check_output(13), true);
}

Test(tests_Component_4008, test_check_input_return_false)
{
    Component_4008 test("test");

    cr_assert_eq(test.check_input(10), false);
    cr_assert_eq(test.check_input(11), false);
    cr_assert_eq(test.check_input(33), false);
    cr_assert_eq(test.check_input(102), false);
}

Test(tests_Component_4008, test_check_output_return_false)
{
    Component_4008 test("test");

    cr_assert_eq(test.check_output(1), false);
    cr_assert_eq(test.check_output(2), false);
    cr_assert_eq(test.check_output(33), false);
    cr_assert_eq(test.check_output(102), false);
}

Test(tests_Component_4008, test_truth_table)
{
    Component_4008 test("test");
    True tru("tru");
    False fals("fals");

    cr_assert_eq(test.compute(10), nts::UNDEFINED);
    cr_assert_eq(test.compute(300), nts::UNDEFINED);
    test.setLink(6, tru, 1);
    test.setLink(7, tru, 1);
    test.setLink(9, fals, 1);
    cr_assert_eq(test.compute(10), nts::FALSE);
    test.setLink(6, tru, 1);
    test.setLink(7, fals, 1);
    test.setLink(9, tru, 1);
    cr_assert_eq(test.compute(10), nts::FALSE);
    test.setLink(4, tru, 1);
    test.setLink(5, tru, 1);
    cr_assert_eq(test.compute(11), nts::TRUE);
    cr_assert_eq(test.compute(12), nts::UNDEFINED);
}

Test(tests_Component_4008, test_truth_C0)
{
    Component_4008 test("test");
    True tru("tru");
    False fals("fals");
    Input undef("undef");

    test.setLink(6, fals, 1);
    test.setLink(7, fals, 1);
    test.setLink(9, fals, 1);
    test.setLink(4, fals, 1);
    test.setLink(5, fals, 1);
    test.setLink(2, fals, 1);
    test.setLink(3, fals, 1);
    test.setLink(1, fals, 1);
    test.setLink(15, fals, 1);
    cr_assert_eq(test.compute(14), nts::FALSE);

    test.setLink(6, tru, 1);
    test.setLink(7, tru, 1);
    test.setLink(9, tru, 1);
    test.setLink(4, tru, 1);
    test.setLink(5, tru, 1);
    test.setLink(2, tru, 1);
    test.setLink(3, tru, 1);
    test.setLink(1, tru, 1);
    test.setLink(15, tru, 1);
    cr_assert_eq(test.compute(14), nts::TRUE);

    test.setLink(6, tru, 1);
    test.setLink(7, tru, 1);
    test.setLink(9, fals, 1);
    test.setLink(4, tru, 1);
    test.setLink(5, tru, 1);
    test.setLink(2, tru, 1);
    test.setLink(3, tru, 1);
    test.setLink(1, tru, 1);
    test.setLink(15, tru, 1);
    cr_assert_eq(test.compute(14), nts::TRUE);

    test.setLink(6, fals, 1);
    test.setLink(7, fals, 1);
    test.setLink(9, tru, 1);
    test.setLink(4, fals, 1);
    test.setLink(5, fals, 1);
    test.setLink(2, fals, 1);
    test.setLink(3, fals, 1);
    test.setLink(1, fals, 1);
    test.setLink(15, fals, 1);
    cr_assert_eq(test.compute(14), nts::FALSE);

    test.setLink(6, tru, 1);
    test.setLink(7, tru, 1);
    test.setLink(9, tru, 1);
    test.setLink(4, tru, 1);
    test.setLink(5, tru, 1);
    test.setLink(2, tru, 1);
    test.setLink(3, tru, 1);
    test.setLink(1, tru, 1);
    test.setLink(15, fals, 1);
    cr_assert_eq(test.compute(14), nts::TRUE);

    test.setLink(6, tru, 1);
    test.setLink(7, tru, 1);
    test.setLink(9, tru, 1);
    test.setLink(4, undef, 1);
    test.setLink(5, tru, 1);
    test.setLink(2, tru, 1);
    test.setLink(3, tru, 1);
    test.setLink(1, tru, 1);
    test.setLink(15, fals, 1);
    //cr_assert_eq(test.compute(13), nts::UNDEFINED);
}