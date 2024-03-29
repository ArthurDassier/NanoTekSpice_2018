/*
** EPITECH PROJECT, 2019
** Component_4503.cpp
** File description:
** 4503
*/

#include "Component_4503.hpp"

Component_4503::Component_4503(std::string name)
{
    _name = name;
    _type = "4503";
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 16; ++i)
        _list.push_back(setter);
}

Component_4503::~Component_4503()
{
}

nts::Tristate Component_4503::operand(std::size_t in1, std::size_t in2)
{
    if (_list[in1].cmp == NULL || _list[in2].cmp == NULL)
        return (nts::UNDEFINED);
    nts::Tristate one = _list[in1].cmp->compute(_list[in1].output);
    nts::Tristate two = _list[in2].cmp->compute(_list[in2].output);
    if (one == nts::FALSE || two == nts::UNDEFINED)
        return (nts::UNDEFINED);
    if (one == nts::TRUE || !(two == nts::TRUE))
        return (nts::TRUE);
    return (nts::FALSE);
}

nts::Tristate Component_4503::compute(std::size_t pin)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin == 3)
        return (operand(1, 2));
    if (pin == 5)
        return (operand(1, 4));
    if (pin == 7)
        return (operand(1, 6));
    if (pin == 9)
        return (operand(1, 10));
    if (pin == 11)
        return (operand(12, 15));
    if (pin == 13)
        return (operand(14, 15));
    return (nts::FALSE);
}

bool Component_4503::check_input(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 4 || pin == 6
    || pin == 10 || pin == 12 || pin == 14 || pin == 15)
        return (true);
    return (false);
}

bool Component_4503::check_output(std::size_t pin)
{
    if (pin == 3 || pin == 5 || pin == 7 || pin == 9 || pin == 11 || pin == 13)
        return (true);
    return (false);
}
