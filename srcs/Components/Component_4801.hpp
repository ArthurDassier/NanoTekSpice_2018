/*
** EPITECH PROJECT, 2019
** Component_4801.h
** File description:
** 4801
*/

#ifndef COMPONENT_4801_HPP_
	#define COMPONENT_4801_HPP_

#include "IComponent.hpp"

class Component_4801 : public nts::IComponent
{
    public:
        Component_4801(std::string name);
        ~Component_4801();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

    private:
        std::string _name;
};

Component_4801::Component_4801(std::string name) :
    _name(name)
{
}

Component_4801::~Component_4801()
{
}

std::string Component_4801::getName()
{
    return (_name);
}

nts::Tristate Component_4801::compute(std::size_t pin = 1)
{

}

void Component_4801::dump() const
{

}

void Component_4801::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}


#endif /* !COMPONENT_4801_HPP_ */
