/*
** EPITECH PROJECT, 2019
** Component_4030.cpp
** File description:
** 4030
*/

#include "Component_4030.hpp"

Component_4030::Component_4030(std::string name)
{
    _name = name;
    _type = "4030";
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 14; ++i)
        _list.push_back(setter);
}

Component_4030::~Component_4030()
{
}

nts::Tristate Component_4030::operand(std::size_t in1, std::size_t in2)
{
    nts::Tristate one = nts::UNDEFINED;
    nts::Tristate two = nts::UNDEFINED;

    if (_list[in1].cmp == NULL || _list[in2].cmp == NULL)
        return (nts::UNDEFINED);
    one = _list[in1].cmp->compute(_list[in1].output);
    two = _list[in2].cmp->compute(_list[in2].output);
    if (one == nts::UNDEFINED || one == nts::UNDEFINED)
        return (nts::UNDEFINED);
    if ((one == nts::TRUE) ^ (two == nts::TRUE))
        return (nts::TRUE);
    return (nts::FALSE);
}

nts::Tristate Component_4030::compute(std::size_t pin)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin == 3)
        return (operand(1, 2));
    if (pin == 4)
        return (operand(5, 6));
    if (pin == 10)
        return (operand(8, 9));
    if (pin == 11)
        return (operand(12, 13));
    return (nts::UNDEFINED);
}

bool Component_4030::check_input(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 5 || pin == 6 || pin == 8
    || pin == 9 || pin == 12 || pin == 13)
        return (true);
    return (false);
}

bool Component_4030::check_output(std::size_t pin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
        return (true);
    return (false);
}


