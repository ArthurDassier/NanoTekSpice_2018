/*
** EPITECH PROJECT, 2019
** Component_2716.cpp
** File description:
** 2716
*/

#include "Component_2716.hpp"

Component_2716::Component_2716(std::string name)
{
    _name = name;
    _type = "2716";
}

Component_2716::~Component_2716()
{
}

nts::Tristate Component_2716::compute(std::size_t pin)
{
    (void)pin;
    return (nts::UNDEFINED);
}

bool Component_2716::check_input(std::size_t pin)
{
    if ((pin >= 1 && pin <= 8) || pin == 19 || pin == 22 || pin == 23)
        return (true);
    return (false);
}

bool Component_2716::check_output(std::size_t pin)
{
    if ((pin >= 9 && pin <= 11) || (pin >= 13 && pin <= 17))
        return (true);
    return (false);
}

