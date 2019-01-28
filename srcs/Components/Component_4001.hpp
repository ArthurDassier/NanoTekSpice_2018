/*
** EPITECH PROJECT, 2019
** Component_4001.h
** File description:
** 4001
*/

#ifndef COMPONENT_4001_HPP_
	#define COMPONENT_4001_HPP_

#include "IComponent.hpp"

class Component_4001 : public nts::IComponent
{
    public:
        Component_4001(std::string);
        ~Component_4001();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

    private:
        std::string _name;
};

Component_4001::Component_4001(std::string name) :
    _name(name)
{
}

Component_4001::~Component_4001()
{
}

std::string Component_4001::getName()
{
    return (_name);
}

nts::Tristate Component_4001::compute(std::size_t pin = 1)
{

}

void Component_4001::dump() const
{

}

void Component_4001::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4001_HPP_ */
