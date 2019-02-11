/*
** EPITECH PROJECT, 2019
** tests_Special_Components.cpp
** File description:
** tests_Special_Components
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "IComponent.hpp"
#include "Clock.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"

Test(tests_Special_Components, test_check_construction)
{
    Clock cloc("test");
    False fals("test");
    True tru("test");
    Input inpu("test");
    Output outpu("test");

    cr_assert_eq(cloc.getName(), "test");
    cr_assert_eq(cloc.getType(), "clock");

    cr_assert_eq(fals.getName(), "test");
    cr_assert_eq(fals.getType(), "false");

    cr_assert_eq(tru.getName(), "test");
    cr_assert_eq(tru.getType(), "true");

    cr_assert_eq(inpu.getName(), "test");
    cr_assert_eq(inpu.getType(), "input");

    cr_assert_eq(outpu.getName(), "test");
    cr_assert_eq(outpu.getType(), "output");
}

Test(tests_Special_Components, test_clock)
{
    Clock test("test");

    cr_assert_eq(test.check_input(1), false);
    cr_assert_eq(test.check_output(1), true);
    cr_assert_eq(test.check_output(2), false);
    test.setClock(nts::TRUE);
    cr_assert_eq(test.compute(1), nts::TRUE);
    cr_assert_eq(test.compute(1), nts::FALSE);
}

Test(tests_Special_Components, test_output)
{
    Output test("test");
    False fals("test");

    cr_assert_eq(test.check_input(1), true);
    cr_assert_eq(test.check_input(2), false);
    cr_assert_eq(test.check_output(1), false);
    test.setLink(1, fals, 1);
    cr_assert_eq(test.compute(1), nts::FALSE);
}

Test(tests_Special_Components, test_input)
{
    Input test("test");

    cr_assert_eq(test.check_input(1), false);
    cr_assert_eq(test.check_output(1), true);
    cr_assert_eq(test.check_output(2), false);
    test.setInput(nts::TRUE);
    cr_assert_eq(test.compute(1), nts::TRUE);
}

Test(tests_Special_Components, test_true)
{
    True test("test");

    cr_assert_eq(test.check_output(1), true);
    cr_assert_eq(test.check_output(2), false);
    cr_assert_eq(test.check_input(3), false);
    cr_assert_eq(test.compute(1), nts::TRUE);
    cr_assert_eq(test.compute(11), nts::UNDEFINED);
}

Test(tests_Special_Components, test_false)
{
    False test("test");

    cr_assert_eq(test.check_output(1), true);
    cr_assert_eq(test.check_output(2), false);
    cr_assert_eq(test.check_input(3), false);
    cr_assert_eq(test.compute(1), nts::FALSE);
    cr_assert_eq(test.compute(11), nts::UNDEFINED);
}