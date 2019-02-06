/*
** EPITECH PROJECT, 2019
** Component_2716.cpp
** File description:
** 2716
*/

#include "Component_2716.hpp"

Component_2716::Component_2716(std::string name) :
    _name(name),
    _type("2716")
{
}

Component_2716::~Component_2716()
{
}

std::string Component_2716::getName() const
{
    return (_name);
}

std::string Component_2716::getType() const
{
    return (_type);
}

nts::Tristate Component_2716::compute(std::size_t pin)
{
    return (nts::UNDEFINED);
}

void Component_2716::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_2716::check_input(std::size_t pin)
{
    if (pin >= 1 && pin <= 8 || pin == 19 || pin == 22 || pin == 23)
        return (true);
    return (false);
}

bool Component_2716::check_output(std::size_t pin)
{
    if (pin >= 9 && pin <= 11 || pin >= 13 && pin <= 17)
        return (true);
    return (false);
}

void Component_2716::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::link_t setter;

    if (check_input(pin)) {
        setter.cmp = &other;
        setter.output = otherPin;
        _list[pin] = setter;
    }
}
