/*
** EPITECH PROJECT, 2019
** Tests_Circus
** File description:
** Circus_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Circus.hpp"
#include "True.hpp"
#include "False.hpp"

Test(tests_Circus, test_getCircus)
{
    Circus test;
    True tru("test");
    std::vector<nts::IComponent *> my_test;

    my_test.push_back(&tru);
    test.addComponent(tru);
    cr_assert_eq(test.getCircus(), my_test);
    test.removeComponent("test");
}