/*
** EPITECH PROJECT, 2019
** Component_4013.h
** File description:
** 4013
*/

#ifndef COMPONENT_4013_HPP_
	#define COMPONENT_4013_HPP_

#include "IComponent.hpp"

class Component_4013 : public nts::IComponent
{
    public:
        Component_4013();
        ~Component_4013();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
};

Component_4013::Component_4013()
{
}

Component_4013::~Component_4013()
{
}

nts::Tristate Component_4013::compute(std::size_t pin = 1)
{

}

void Component_4013::dump() const
{

}

void Component_4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4013_HPP_ */
