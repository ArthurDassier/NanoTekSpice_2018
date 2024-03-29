/*
** EPITECH PROJECT, 2019
** Component_4011.cpp
** File description:
** 4011
*/

#include "Component_4011.hpp"

Component_4011::Component_4011(std::string name)
{
    _name = name;
    _type = "4011";
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 14; ++i)
        _list.push_back(setter);
}

Component_4011::~Component_4011()
{
}

nts::Tristate Component_4011::operand(std::size_t in1, std::size_t in2)
{
    if (_list[in1].cmp == NULL || _list[in2].cmp == NULL)
        return (nts::UNDEFINED);
    nts::Tristate one = _list[in1].cmp->compute(_list[in1].output);
    nts::Tristate two = _list[in2].cmp->compute(_list[in2].output);
    if (one == nts::UNDEFINED || two == nts::UNDEFINED) {
        if (one == nts::FALSE || two == nts::FALSE)
            return (nts::TRUE);
        return (nts::UNDEFINED);
    }
    if (one == nts::TRUE && two == nts::TRUE)
        return (nts::FALSE);
    return (nts::TRUE);
}

nts::Tristate Component_4011::compute(std::size_t pin)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin == 3)
        return (operand(1, 2));
    if (pin == 4)
        return (operand(5, 6));
    if (pin == 10)
        return (operand(9, 8));
    if (pin == 11)
        return (operand(12, 13));
    return (nts::UNDEFINED);
}

bool Component_4011::check_input(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 5 || pin == 6 || pin == 8
    || pin == 9 || pin == 12  || pin == 13)
        return (true);
    return (false);
}

bool Component_4011::check_output(std::size_t pin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
        return (true);
    return (false);
}
