/*
** EPITECH PROJECT, 2019
** Component_4030.h
** File description:
** 4030
*/

#ifndef COMPONENT_4030_HPP_
	#define COMPONENT_4030_HPP_

#include "IComponent.hpp"

class Component_4030 : public nts::IComponent
{
    public:
        Component_4030();
        ~Component_4030();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
};

Component_4030::Component_4030()
{
}

Component_4030::~Component_4030()
{
}

nts::Tristate Component_4030::compute(std::size_t pin = 1)
{

}

void Component_4030::dump() const
{

}

void Component_4030::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4030_HPP_ */
