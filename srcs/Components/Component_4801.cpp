/*
** EPITECH PROJECT, 2019
** Component_4801.h
** File description:
** 4801
*/

#include "Component_4801.hpp"

Component_4801::Component_4801(std::string name)
{
    _name = name;
    _type = "4801";
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 13; ++i)
        _list.push_back(setter);
}

Component_4801::~Component_4801()
{
}

nts::Tristate Component_4801::compute(std::size_t pin)
{
    return (nts::UNDEFINED);
}

void Component_4801::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4801::check_input(std::size_t pin)
{
    return (false);
}

bool Component_4801::check_output(std::size_t pin)
{
    return (false);
}
