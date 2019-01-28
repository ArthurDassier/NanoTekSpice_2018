/*
** EPITECH PROJECT, 2019
** Component_4017.h
** File description:
** 4017
*/

#ifndef COMPONENT_4017_HPP_
	#define COMPONENT_4017_HPP_

#include "IComponent.hpp"

class Component_4017 : public nts::IComponent
{
    public:
        Component_4017();
        ~Component_4017();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
};

Component_4017::Component_4017()
{
}

Component_4017::~Component_4017()
{
}

nts::Tristate Component_4017::compute(std::size_t pin = 1)
{

}

void Component_4017::dump() const
{

}

void Component_4017::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4017_HPP_ */
