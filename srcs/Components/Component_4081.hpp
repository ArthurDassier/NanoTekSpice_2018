/*
** EPITECH PROJECT, 2019
** Component_4081.h
** File description:
** 4081
*/

#ifndef COMPONENT_4081_HPP_
	#define COMPONENT_4081_HPP_

#include "IComponent.hpp"

class Component_4081 : public nts::IComponent
{
    public:
        Component_4081(std::string);
        ~Component_4081();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

    private:
        std::string _name;
};

Component_4081::Component_4081(std::string name) :
    _name(name)
{
}

Component_4081::~Component_4081()
{
}

std::string Component_4081::getName()
{
    return (_name);
}


nts::Tristate Component_4081::compute(std::size_t pin = 1)
{

}

void Component_4081::dump() const
{

}

void Component_4081::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4081_HPP_ */
