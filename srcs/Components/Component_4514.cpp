/*
** EPITECH PROJECT, 2019
** Component_4514.cpp
** File description:
** 4514
*/

#include "Component_4514.hpp"

Component_4514::Component_4514(std::string name)
{
    _name = name;
    _type = "4514";
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 24; ++i)
        _list.push_back(setter);
}

Component_4514::~Component_4514()
{
}

nts::Tristate Component_4514::operand(std::size_t in1, std::size_t in2)
{
    (void)in1;
    (void)in2;
    return (nts::UNDEFINED);
}

nts::Tristate Component_4514::compute(std::size_t pin)
{
    int a = 1;
    int b = 2;
    int c = 4;
    int d = 8;
    size_t res = 0;
    nts::Tristate val;

    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (_list[1].cmp == NULL || _list[3].cmp == NULL || _list[21].cmp == NULL
    ||_list[22].cmp == NULL || _list[23].cmp == NULL)
        return (nts::UNDEFINED);
    if (_list[1].cmp->compute(_list[1].output) == nts::TRUE)
        res += a;
    if (_list[3].cmp->compute(_list[3].output) == nts::TRUE)
        res += b;
    if (_list[21].cmp->compute(_list[21].output) == nts::TRUE)
        res += c;
    if (_list[22].cmp->compute(_list[22].output) == nts::TRUE)
        res += d;
    val = _list[23].cmp->compute(_list[23].output);
    if (pin <= 11) {
        if ((res + 4) == pin && val == nts::FALSE)
            return (nts::TRUE);
        if ((res + 4) == pin && val == nts::TRUE)
            return (nts::FALSE);
    }
    if (pin >= 13) {
        if ((res + 5) == pin && val == nts::FALSE)
            return (nts::TRUE);
        if ((res + 5) == pin && val == nts::TRUE)
            return (nts::FALSE);
    }
    return (nts::UNDEFINED);
}

bool Component_4514::check_input(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 3 || pin == 21
    || pin == 22 || pin == 23)
        return (true);
    return (false);
}

bool Component_4514::check_output(std::size_t pin)
{
    if ((pin >= 4 && pin <= 11) || (pin >= 13 && pin <= 20))
        return (true);
    return (false);
}
