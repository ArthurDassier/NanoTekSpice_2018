/*
** EPITECH PROJECT, 2019
** Component_4069.h
** File description:
** 4069
*/

#ifndef COMPONENT_4069_HPP_
	#define COMPONENT_4069_HPP_

#include "IComponent.hpp"

class Component_4069 : public nts::IComponent
{
    public:
        Component_4069(std::string);
        ~Component_4069();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

    private:
        std::string _name;
};

Component_4069::Component_4069(std::string name) :
    _name(name)
{
}

Component_4069::~Component_4069()
{
}

nts::Tristate Component_4069::compute(std::size_t pin = 1)
{

}

void Component_4069::dump() const
{

}

void Component_4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4069_HPP_ */
