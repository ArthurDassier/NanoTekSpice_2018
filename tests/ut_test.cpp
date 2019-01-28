/*
** EPITECH PROJECT, 2018
** toto
** File description:
** ut_test.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

bool my_test(int mode);

Test(test, just_for_sonar_pos)
{
    cr_assert_eq(my_test(0), false);
}

Test(test, just_for_sonar_neg)
{
    cr_assert_eq(my_test(34), true);
}
