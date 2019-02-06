/*
** EPITECH PROJECT, 2019
** Component_4013.cpp
** File description:
** 4013
*/

#include "Component_4013.hpp"

Component_4013::Component_4013(std::string name) :
    _name(name),
    _type("4013")
{
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 14; ++i)
        _list.push_back(setter);
}

Component_4013::~Component_4013()
{
}

std::string Component_4013::getName() const
{
    return (_name);
}

std::string Component_4013::getType() const
{
    return (_type);
}

nts::Tristate Component_4013::compute(std::size_t pin)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
}

void Component_4013::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4013::check_input(std::size_t pin)
{
    if (pin >= 3 && pin <= 6 || pin >= 8 && pin <= 11)
        return (true);
    return (false);
}

bool Component_4013::check_output(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 12 || pin == 13)
        return (true);
    return (false);
}

void Component_4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::link_t setter;

    if (check_input(pin)) {
        setter.cmp = &other;
        setter.output = otherPin;
        _list[pin] = setter;
    }
}
