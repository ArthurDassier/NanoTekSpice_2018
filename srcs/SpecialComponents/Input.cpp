/*
** EPITECH PROJECT, 2019
** Input.cpp
** File description:
** INput
*/

#include "Input.hpp"

Input::Input(std::string name) :
    _name(name),
    _type("Input")
{
    _input = nts::UNDEFINED;
}

Input::~Input()
{
}

std::string Input::getName() const
{
    return (_name);
}

std::string Input::getType() const
{
    return (_type);
}

nts::Tristate Input::compute(std::size_t pin)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    return (_input);
}

void Input::dump() const
{
    std::cout << _name << std::endl;
}

bool Input::check_input(std::size_t pin)
{
    return (false);
}

bool Input::check_output(std::size_t pin)
{
    if (pin == 1)
        return (true);
    return (false);
}

void Input::setInput(nts::Tristate state)
{
    _input = state;
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    return;
}
