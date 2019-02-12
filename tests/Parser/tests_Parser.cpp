/*
** EPITECH PROJECT, 2019
** tests_Parser.cpp
** File description:
** tests_Parser
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Circus.hpp"
#include "Factory.hpp"
#include "Parser.hpp"
#include "Component.hpp"

Test(tests_parser, test_basic_and)
{
    Circus circus;
    Factory factory;
    parser::Parser parser("files/and.nts", circus, factory);
    parser.LetsParse();
    cr_assert_eq("OK", "OK");
}

Test(tests_parser, test_basic_nor)
{
    Circus circus;
    Factory factory;
    parser::Parser parser("files/nor.nts", circus, factory);
    parser.LetsParse();
    cr_assert_eq("OK", "OK");
}

Test(tests_parser, test_basic_xor)
{
    Circus circus;
    Factory factory;
    parser::Parser parser("files/xor.nts", circus, factory);
    parser.LetsParse();
    cr_assert_eq("OK", "OK");
}

Test(tests_parser, test_basic_adder)
{
    Circus circus;
    Factory factory;
    parser::Parser parser("files/adder.nts", circus, factory);
    parser.LetsParse();
    cr_assert_eq("OK", "OK");
}

Test(tests_parser, test_main_error)
{
    Circus circus;
    Factory factory;
    parser::Parser parser("toto", circus, factory);
    std::vector<std::string> stock;
    stock.push_back(".links:");
    stock.push_back(".chipsets:");
    cr_assert_eq(parser.CheckMainError(stock), true);
}

Test(tests_parser, test_main_error_only_links)
{
    Circus circus;
    Factory factory;
    parser::Parser parser("toto", circus, factory);
    std::vector<std::string> stock;
    stock.push_back(".links:");
    cr_assert_any_throw(parser.CheckMainError(stock));
}

Test(tests_parser, test_main_error_only_chipset)
{
    Circus circus;
    Factory factory;
    parser::Parser parser("toto", circus, factory);
    std::vector<std::string> stock;
    stock.push_back(".chipsets:");
    cr_assert_any_throw(parser.CheckMainError(stock));
}
