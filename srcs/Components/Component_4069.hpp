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

Component_4069::Component_4069(std::string name) :
    _name(name)
{
}

Component_4069::~Component_4069()
{
}

nts::Tristate Component_4069::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (inputs[pin - 1].compute(pin - 1) == nts::TRUE)
        return (nts::FALSE);
    else
        return (nts::TRUE);
    return (nts::UNDEFINED);
}

void Component_4069::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4069::check_input(std::size_t pin)
{
    if (pin == 1 || pin == 3 || pin == 5 || pin == 9 || pin == 11 || pin == 13)
        return (true);
    return (false);
}

bool Component_4069::check_output(std::size_t pin)
{
    if (pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12)
        return (true);
    return (false);
}

void Component_4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}

#endif /* !COMPONENT_4069_HPP_ */
