/*
** EPITECH PROJECT, 2019
** Component_4071.h
** File description:
** 4071
*/

#ifndef COMPONENT_4071_HPP_
	#define COMPONENT_4071_HPP_

#include "IComponent.hpp"

class Component_4071 : public nts::IComponent
{
    public:
        Component_4071(std::string);
        ~Component_4071();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

    private:
        std::string _name;
};

Component_4071::Component_4071(std::string name) :
    _name(name)
{
}

Component_4071::~Component_4071()
{
}

std::string Component_4071::getName()
{
    return (_name);
}

nts::Tristate Component_4071::compute(std::size_t pin = 1)
{

}

void Component_4071::dump() const
{

}

void Component_4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4071_HPP_ */
