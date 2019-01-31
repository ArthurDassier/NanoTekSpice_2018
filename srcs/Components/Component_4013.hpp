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
        Component_4013(std::string);
        ~Component_4013();

        // Members
        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

        bool check_input(std::size_t);
        bool check_output(std::size_t);

    private:
        std::string _name;
        std::unordered_map<std::size_t, nts::IComponent &> inputs;
        std::unordered_map<std::size_t, std::size_t> output;
};

Component_4013::Component_4013(std::string name) :
    _name(name)
{
    for(size_t i = 1; i != 14; ++i)
        output[i] = 0;
}

Component_4013::~Component_4013()
{
}

nts::Tristate Component_4013::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
}

void Component_4013::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4013::check_input(std::size_t pin)
{
    if (pin >= 3 && pin <= 6 || pin >= 8 && pin <= 11)
        return (true);
    return (false);
}

bool Component_4013::check_output(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 12 || pin == 13)
        return (true);
    return (false);
}

void Component_4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}

#endif /* !COMPONENT_4013_HPP_ */
