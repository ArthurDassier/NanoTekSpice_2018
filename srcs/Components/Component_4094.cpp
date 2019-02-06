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
    // for(size_t i = 1; i != 14; ++i)
    //    output[i] = 0;
}

Component_4094::~Component_4094()
{
}

nts::Tristate Component_4094::compute(std::size_t pin)
{
    return (nts::UNDEFINED);
}

void Component_4094::dump() const
{

}

bool Component_4094::check_input(std::size_t pin)
{
    return (false);
}

bool Component_4094::check_output(std::size_t pin)
{
    return (false);
}
