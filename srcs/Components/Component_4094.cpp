/*
** EPITECH PROJECT, 2019
** Component_4094
** File description:
** 4094
*/

#include "Component_4094.hpp"

Component_4094::Component_4094(std::string name) :
    _name(name)
{
    // for(size_t i = 1; i != 14; ++i)
    //    output[i] = 0;
}

Component_4094::~Component_4094()
{
}

std::string Component_4094::getName()
{
    return (_name);
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

void Component_4094::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::link_t setter;

    if (check_input(pin)) {
        setter.cmp = &other;
        setter.output = otherPin;
        _list[pin] = setter;
    }
}