/*
** EPITECH PROJECT, 2019
** Component_4094
** File description:
** 4094
*/

#include "Component_4094.hpp"

Component_4094::Component_4094(std::string name)
{
    _name = name;
    _type = "4094";
}

Component_4094::~Component_4094()
{
}

nts::Tristate Component_4094::compute(std::size_t pin)
{
    (void)pin;
    return (nts::UNDEFINED);
}

bool Component_4094::check_input(std::size_t pin)
{
    (void)pin;
    return (false);
}

bool Component_4094::check_output(std::size_t pin)
{
    (void)pin;
    return (false);
}
