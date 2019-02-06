/*
** EPITECH PROJECT, 2019
** Component_4017.cpp
** File description:
** 4017
*/

#include "Component_4017.hpp"


Component_4017::Component_4017(std::string name) :
    _name(name),
    _type("4017")
{
}

Component_4017::~Component_4017()
{
}

std::string Component_4017::getName() const
{
    return (_name);
}

nts::Tristate Component_4017::compute(std::size_t pin)
{
    return (nts::UNDEFINED);
}

std::string Component_4017::getType() const
{
    return (_type);
}

void Component_4017::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4017::check_input(std::size_t pin)
{
    if (pin >= 1 && pin <= 7 || pin >= 9 && pin <= 11)
        return (true);
    return (false);
}

bool Component_4017::check_output(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 12 || pin == 13)
        return (true);
    return (false);
}

void Component_4017::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::link_t setter;

    if (check_input(pin)) {
        setter.cmp = &other;
        setter.output = otherPin;
        _list[pin] = setter;
    }
}
