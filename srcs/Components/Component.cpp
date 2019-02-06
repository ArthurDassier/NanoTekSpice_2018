/*
** EPITECH PROJECT, 2019
** Abstract_Component.cpp
** File description:
** Abstract
*/

#include "Component.hpp"

Component::Component()
{
}

Component::~Component()
{
}

std::string Component::getName() const
{
    return (_name);
}

std::string Component::getType() const
{
    return (_type);
}

void Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::link_t setter;

    if (check_input(pin)) {
        setter.cmp = &other;
        setter.output = otherPin;
        _list[pin] = setter;
    }
}

