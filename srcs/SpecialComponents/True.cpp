/*
** EPITECH PROJECT, 2019
** True.cpp
** File description:
** True
*/

#include "True.hpp"

True::True(std::string name) :
    _name(name),
    _type("true")
{
}

True::~True()
{
}

std::string True::getName() const
{
    return (_name);
}

std::string True::getType() const
{
    return (_type);
}

nts::Tristate True::compute(std::size_t pin)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    return (nts::TRUE);
}

void True::dump() const
{
    std::cout << _name << std::endl;
}

bool True::check_input(std::size_t pin)
{
    (void)pin;
    return (false);
}

bool True::check_output(std::size_t pin)
{
    if (pin == 1)
        return (true);
    return (false);
}

void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
    return;
}