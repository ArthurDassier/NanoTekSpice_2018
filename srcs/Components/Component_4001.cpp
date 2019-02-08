/*
** EPITECH PROJECT, 2019
** Component_4001.h
** File description:
** 4001
*/

#include "Component_4001.hpp"

Component_4001::Component_4001(std::string name)
{
    _name = name;
    _type = "4001";
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 13; ++i)
        _list.push_back(setter);
}

Component_4001::~Component_4001()
{
}

nts::Tristate Component_4001::operand(std::size_t in1, std::size_t in2)
{
    if (_list[in1].cmp == NULL || _list[in2].cmp == NULL)
        return (nts::UNDEFINED);
    if (_list[in1].cmp->compute(_list[in1].output) == nts::TRUE
    || _list[in2].cmp->compute(_list[in2].output) == nts::TRUE)
        return (nts::FALSE);
    else if (_list[in1].cmp->compute(_list[in1].output) == nts::UNDEFINED
    || _list[in2].cmp->compute(_list[in2].output) == nts::UNDEFINED)
        return (nts::UNDEFINED);
    else
        return (nts::TRUE);
}

nts::Tristate Component_4001::compute(std::size_t pin)
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

bool Component_4001::check_input(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 5 || pin == 6 ||
    pin == 8 || pin == 9 || pin == 12 || pin == 13)
        return (true);
    return (false);
}

bool Component_4001::check_output(std::size_t pin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
        return (true);
    return (false);
}

