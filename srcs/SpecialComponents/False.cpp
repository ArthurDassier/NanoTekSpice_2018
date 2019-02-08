/*
** EPITECH PROJECT, 2019
** False.cpp
** File description:
** False
*/

#include "False.hpp"

False::False(std::string name) :
    _name(name),
    _type("False")
{
}

False::~False()
{
}

std::string False::getName() const
{
    return (_name);
}

std::string False::getType() const
{
    return (_type);
}

nts::Tristate False::compute(std::size_t pin)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    return (nts::FALSE);
}

void False::dump() const
{
    std::cout << _name << std::endl;
}

bool False::check_input(std::size_t pin)
{
    return (false);
}

bool False::check_output(std::size_t pin)
{
    if (pin == 1)
        return (true);
    return (false);
}

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    return;
}