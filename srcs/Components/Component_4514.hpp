/*
** EPITECH PROJECT, 2019
** Component_4514.h
** File description:
** 4514
*/

#ifndef COMPONENT_4514_HPP_
	#define COMPONENT_4514_HPP_

#include "IComponent.hpp"

class Component_4514 : public nts::IComponent
{
    public:
        Component_4514();
        ~Component_4514();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
};

Component_4514::Component_4514()
{
}

Component_4514::~Component_4514()
{
}

nts::Tristate Component_4514::compute(std::size_t pin = 1)
{

}

void Component_4514::dump() const
{

}

void Component_4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4514_HPP_ */
