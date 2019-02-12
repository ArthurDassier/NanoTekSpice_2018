/*
** EPITECH PROJECT, 2019
** tests_Parser.cpp
** File description:
** tests_Factory
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Factory.hpp"

Test(tests_parser, test_factory)
{
    Factory factory;

    cr_assert(dynamic_cast<Component_4001*>(factory.create4001("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_4008*>(factory.create4008("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_4013*>(factory.create4013("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_4011*>(factory.create4011("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_4017*>(factory.create4017("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_4030*>(factory.create4030("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_4040*>(factory.create4040("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_4069*>(factory.create4069("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_4071*>(factory.create4071("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_4081*>(factory.create4081("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_4094*>(factory.create4094("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_4514*>(factory.create4514("toto")) != nullptr);
    cr_assert(dynamic_cast<Component_2716*>(factory.create2716("toto")) != nullptr);

    cr_assert(dynamic_cast<True*>(factory.createTrue("toto")) != nullptr);
    cr_assert(dynamic_cast<False*>(factory.createFalse("toto")) != nullptr);
    cr_assert(dynamic_cast<Input*>(factory.createInput("toto")) != nullptr);
    cr_assert(dynamic_cast<Output*>(factory.createOutput("toto")) != nullptr);
    cr_assert(dynamic_cast<Clock*>(factory.createClock("toto")) != nullptr);
}
