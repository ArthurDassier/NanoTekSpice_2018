/*
** EPITECH PROJECT, 2019
** Component_4094.h
** File description:
** 4094
*/

#ifndef COMPONENT_4094_HPP_
	#define COMPONENT_4094_HPP_

#include "IComponent.hpp"

class Component_4094 : public nts::IComponent
{
    public:
        Component_4094();
        ~Component_4094();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
};

Component_4094::Component_4094()
{
}

Component_4094::~Component_4094()
{
}

nts::Tristate Component_4094::compute(std::size_t pin = 1)
{

}

void Component_4094::dump() const
{

}

void Component_4094::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4094_HPP_ */
