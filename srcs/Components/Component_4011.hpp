/*
** EPITECH PROJECT, 2019
** Component_4011.h
** File description:
** 4011
*/

#ifndef COMPONENT_4011_HPP_
	#define COMPONENT_4011_HPP_

#include "IComponent.hpp"

class Component_4011 : public nts::IComponent
{
    public:
        Component_4011(std::string);
        ~Component_4011();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

    private:
        std::string _name;
};

Component_4011::Component_4011(std::string name) :
    _name(name)
{
}

Component_4011::~Component_4011()
{
}

std::string Component_4011::getName()
{
    return (_name);
}

nts::Tristate Component_4011::compute(std::size_t pin = 1)
{

}

void Component_4011::dump() const
{

}

void Component_4011::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4011_HPP_ */
