/*
** EPITECH PROJECT, 2019
** Component_4040.cpp
** File description:
** 4040
*/

#include "Component_4040.hpp"

Component_4040::Component_4040(std::string name) :
    _name(name),
    _type("4040")
{
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 16; ++i)
        _list.push_back(setter);
}

Component_4040::~Component_4040()
{
}

std::string Component_4040::getName() const
{
    return (_name);
}

std::string Component_4040::getType() const
{
    return (_type);
}

nts::Tristate Component_4040::compute(std::size_t pin)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (_list[pin].cmp == NULL || _list[11].cmp == NULL)
        return (nts::UNDEFINED);
    if (_list[11].cmp->compute(_list[11].output) == nts::TRUE)
        return (nts::FALSE);
    else
        return (_list[pin].cmp->compute(_list[pin].output));
}

void Component_4040::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4040::check_input(std::size_t pin)
{
    if (pin == 10 || pin == 11)
        return (true);
    return (false);
}

bool Component_4040::check_output(std::size_t pin)
{
    if (pin >= 1 || pin <= 7 || pin >= 12 || pin <= 15)
        return (true);
    return (false);
}

void Component_4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::link_t setter;

    if (check_input(pin)) {
        setter.cmp = &other;
        setter.output = otherPin;
        _list[pin] = setter;
    }
}

