/*
** EPITECH PROJECT, 2019
** Component_4040.h
** File description:
** 4040
*/

#ifndef COMPONENT_4040_HPP_
	#define COMPONENT_4040_HPP_

#include "IComponent.hpp"

class Component_4040 : public nts::IComponent
{
    public:
        Component_4040(std::string);
        ~Component_4040();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

    private:
        std::string _name;
};

Component_4040::Component_4040(std::string name) :
    _name(name)
{
}

Component_4040::~Component_4040()
{
}

std::string Component_4040::getName()
{
    return (_name);
}

nts::Tristate Component_4040::compute(std::size_t pin = 1)
{

}

void Component_4040::dump() const
{

}

void Component_4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4040_HPP_ */
