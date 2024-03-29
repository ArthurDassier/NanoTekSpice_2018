/*
** EPITECH PROJECT, 2019
** Component_4069.cpp
** File description:
** 4069
*/

#include "Component_4069.hpp"

Component_4069::Component_4069(std::string name)
{
    _name = name;
    _type = "4069";
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 14; ++i)
        _list.push_back(setter);
}

Component_4069::~Component_4069()
{
}

nts::Tristate Component_4069::compute(std::size_t pin)
{
    nts::Tristate val;
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin < 7) {
        if (_list[pin - 1].cmp == NULL)
            return (nts::UNDEFINED);
        val = _list[pin - 1].cmp->compute(_list[pin - 1].output);
        if (val == nts::TRUE)
            return (nts::FALSE);
        else if (val == nts::UNDEFINED)
            return (nts::UNDEFINED);
        else
            return (nts::TRUE);
    }
    if (_list[pin + 1].cmp == NULL)
        return (nts::UNDEFINED);
    val = _list[pin + 1].cmp->compute(_list[pin + 1].output);
    if (val == nts::TRUE)
            return (nts::FALSE);
    else if (val == nts::UNDEFINED)
        return (nts::UNDEFINED);
    else
        return (nts::TRUE);
}

bool Component_4069::check_input(std::size_t pin)
{
    if (pin == 1 || pin == 3 || pin == 5 || pin == 9 || pin == 11 || pin == 13)
        return (true);
    return (false);
}

bool Component_4069::check_output(std::size_t pin)
{
    if (pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12)
        return (true);
    return (false);
}

