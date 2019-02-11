/*
** EPITECH PROJECT, 2019
** Output.cpp
** File description:
** output
*/

#include "Output.hpp"

Output::Output(std::string name) :
    _name(name),
    _type("output")
{
}

Output::~Output()
{
}

std::string Output::getName() const
{
    return (_name);
}

std::string Output::getType() const
{
    return (_type);
}

nts::Tristate Output::compute(std::size_t pin)
{
    return (cmp->compute(output));
}

void Output::dump() const
{
    std::cout << _name << std::endl;
}

bool Output::check_input(std::size_t pin)
{
    if (pin == 1)
        return (true);
    return (false);
}

bool Output::check_output(std::size_t pin)
{
    return (false);
}

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        cmp = &other;
        output = otherPin;
    }
}
