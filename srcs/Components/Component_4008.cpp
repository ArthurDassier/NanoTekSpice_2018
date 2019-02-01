/*
** EPITECH PROJECT, 2019
** Component_4008.cpp
** File description:
** 4008
*/

#include "Component_4008.hpp"

Component_4008::Component_4008(std::string name) :
    _name(name)
{
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 15; ++i)
        _list.push_back(setter);
}

Component_4008::~Component_4008()
{
}

nts::Tristate Component_4008::operand(std::size_t in1, std::size_t in2, std::size_t in3)
{
    if (_list[in1].cmp == NULL || _list[in2].cmp == NULL || _list[in3].cmp == NULL)
        return (nts::UNDEFINED);
    if (_list[in1].cmp->compute(_list[in1].output) == nts::TRUE
    ^ _list[in2].cmp->compute(_list[in2].output) == nts::TRUE) {
        if (_list[in3].cmp->compute(_list[in3].output) == nts::FALSE)
            return (nts::TRUE);
        else
            return (nts::FALSE);
    }
    return (nts::UNDEFINED);
}

nts::Tristate Component_4008::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin == 10)
        return (operand(6, 7, 9));
    if (pin == 11)
        return (operand(4, 5, this->compute[10]));
    if (pin == 12)
        return (operand(2, 3, this->compute[11]));
    if (pin == 13)
        return (operand(1, 15, this->compute[12]));
    return (nts::UNDEFINED);
}

void Component_4008::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4008::check_input(std::size_t pin)
{
    if (pin >= 1 && pin <= 7 || pin == 9 || pin == 15)
        return (true);
    return (false);
}

bool Component_4008::check_output(std::size_t pin)
{
    if (pin == 10 || pin == 11 || pin == 12 || pin == 13)
        return (true);
    return (false);
}

void Component_4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::link_t setter;

    if (check_input(pin)) {
        setter.cmp = &other;
        setter.output = otherPin;
        _list[pin] = setter;
    }
}
