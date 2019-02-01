/*
** EPITECH PROJECT, 2019
** Component_4514.cpp
** File description:
** 4514
*/

#include "Component_4514.hpp"

Component_4514::Component_4514(std::string name) :
    _name(name)
{
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
//
}

nts::Tristate Component_4514::compute(std::size_t pin = 1)
{
    int a = 1;
    int b = 2;
    int c = 4;
    int d = 8;
    int res = 0;

    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (_list[1].cmp->compute(_list[1].output) == nts::TRUE)
        res += a;
    if (_list[3].cmp->compute(_list[3].output) == nts::TRUE)
        res += b;
    if (_list[21].cmp->compute(_list[21].output) == nts::TRUE)
        res += c;
    if (_list[22].cmp->compute(_list[22].output) == nts::TRUE)
        res += d;
    if (pin <= 11) {
        if ((res + 4) == pin && _list[23].cmp->compute(_list[23].output) == nts::FALSE)
            return (nts::TRUE);
        if ((res + 4) == pin && _list[23].cmp->compute(_list[23].output) == nts::TRUE)
            return (nts::FALSE);
    }
    if (pin >= 13) {
        if ((res + 5) == pin && _list[23].cmp->compute(_list[23].output) == nts::FALSE)
            return (nts::TRUE);
        if ((res + 5) == pin && _list[23].cmp->compute(_list[23].output) == nts::TRUE)
            return (nts::FALSE);
    }
    return (nts::UNDEFINED);
}

void Component_4514::dump() const
{
    std::cout << _name << std::endl;
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

void Component_4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::link_t setter;

    if (check_input(pin)) {
        setter.cmp = &other;
        setter.output = otherPin;
        _list[pin] = setter;
    }
}
