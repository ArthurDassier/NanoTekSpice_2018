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

        // Member
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
    if (check_output(pin)) {
        return (inputs[pin].compute(output[pin]));
    }
    return (nts::UNDEFINED);
}

void Component_2716::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_2716::check_input(std::size_t pin)
{
    if (pin >= 1 && pin <= 8 || pin == 19 || pin == 22 || pin == 23)
        return (true);
    return (false);
}

bool Component_2716::check_output(std::size_t pin)
{
    if (pin >= 9 && pin <= 11 || pin >= 13 && pin <= 17)
        return (true);
    return (false);
}

void Component_2716::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}

#endif /* !COMPONENT_2716_HPP_ */
