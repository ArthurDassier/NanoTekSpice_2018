/*
** EPITECH PROJECT, 2019
** Component_4008.h
** File description:
** 4008
*/

#ifndef COMPONENT_4008_HPP_
	#define COMPONENT_4008_HPP_

#include "IComponent.hpp"

class Component_4008 : public nts::IComponent
{
    public:
        Component_4008();
        ~Component_4008();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
};

Component_4008::Component_4008()
{
}

Component_4008::~Component_4008()
{
}

nts::Tristate Component_4008::compute(std::size_t pin = 1)
{

}

void Component_4008::dump() const
{

}

void Component_4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4008_HPP_ */
