/*
** EPITECH PROJECT, 2019
** Component_4512.h
** File description:
** 4512
*/

#include "Component_4512.hpp"

Component_4512::Component_4512(std::string name)
{
    _name = name;
    _type = "4512";
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 13; ++i)
        _list.push_back(setter);
}

Component_4512::~Component_4512()
{
}

nts::Tristate Component_4512::compute(std::size_t pin)
{
    (void)pin;
    return (nts::UNDEFINED);
}

bool Component_4512::check_input(std::size_t pin)
{
    (void)pin;
    return (false);
}

bool Component_4512::check_output(std::size_t pin)
{
    (void)pin;
    return (false);
}
