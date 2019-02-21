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
#include "CLI.hpp"

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

Test(tests_parser, test_ouput_not_linked)
{
    Circus circus;
    Factory factory;
    parser::Parser parser("files/andOutputNotLinked.nts", circus, factory);
    std::string tmp;
    std::ifstream file;
    std::vector<std::string> stock;

    file.open("files/andOutputNotLinked.nts");
    while (!file.eof()) {
        getline(file, tmp);
        stock.push_back(tmp);
    }
    cr_assert_any_throw(parser.ParseFile(stock));
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

Test(tests_parser, test_main_no_input_set)
{
    int ac = 2;
    char **av = static_cast<char**>(malloc(sizeof(char*) * 2));

    if (av == NULL)
        exit(84);
    av[0] = strdup("balec");
    av[1] = strdup("files/and.nts");
    Circus circus;
    Factory factory;
    CLI my_CLI(circus);
    std::string name_input;
    std::string value_input;
    size_t tmp = 0;
    parser::Parser parser(av[1], circus, factory);
    parser.LetsParse();
    std::vector<nts::IComponent *> tmp_circus = circus.getCircus();

    if (ac > 1) {
        for (int i = 2; i < ac; i++) {
            if ((tmp = std::string(av[i]).find("=")) == std::string::npos)
                exit(84);
            name_input = std::string(av[i]).substr(0, tmp);
            value_input = std::string(av[i]).substr(tmp + 1, std::string(av[i]).size() - tmp);
            for (auto &it : tmp_circus) {
                if (it->getName() == name_input)
                    static_cast<Input*>(it)->setInput(static_cast<nts::Tristate>(std::stoi(value_input)));
            }
        }
    }
    cr_assert_any_throw(circus.lets_run());
}
