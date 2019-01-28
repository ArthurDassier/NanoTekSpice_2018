/*
** EPITECH PROJECT, 2019
** Component_2716.h
** File description:
** 2716
*/

#ifndef COMPONENT_2716_HPP_
	#define COMPONENT_2716_HPP_

#include "IComponent.hpp"

class Component_2716 : public nts::IComponent
{
    public:
        Component_2716(std::string);
        ~Component_2716();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

    private:
        std::string _name;
};

Component_2716::Component_2716(std::string name) :
    _name(name)
{
}

Component_2716::~Component_2716()
{
}

std::string Component_2716::getName()
{
    return (_name);
}

nts::Tristate Component_2716::compute(std::size_t pin = 1)
{

}

void Component_2716::dump() const
{

}

void Component_2716::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_2716_HPP_ */
