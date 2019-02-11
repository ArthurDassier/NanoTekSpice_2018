/*
** EPITECH PROJECT, 2019
** Clock.cpp
** File description:
** clock
*/

#include "Clock.hpp"

Clock::Clock(std::string name) :
    _name(name),
    _type("clock")
{
    _input = nts::UNDEFINED;
}

Clock::~Clock()
{
}

std::string Clock::getName() const
{
    return (_name);
}

std::string Clock::getType() const
{
    return (_type);
}

nts::Tristate Clock::compute(std::size_t pin)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (_input == nts::TRUE) {
        _input = nts::FALSE;
        return (nts::TRUE);
    } else {
        _input = nts::TRUE;
        return (nts::FALSE);
    }
}

void Clock::dump() const
{
    std::cout << _name << std::endl;
}

bool Clock::check_input(std::size_t pin)
{
    return (false);
}

bool Clock::check_output(std::size_t pin)
{
    if (pin == 1)
        return (true);
    return (false);
}

void Clock::setClock(nts::Tristate state)
{
    _input = state;
}

void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    return;
}
