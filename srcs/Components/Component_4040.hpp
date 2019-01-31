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

        bool check_input(std::size_t);
        bool check_output(std::size_t);

    private:
        std::string _name;
        std::unordered_map<std::size_t, nts::IComponent &> inputs;
        std::unordered_map<std::size_t, std::size_t> output;
};

Component_4040::Component_4040(std::string name) :
    _name(name)
{
    for(size_t i = 1; i != 16; ++i)
        output[i] = 0;
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
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (output[pin] == 0 || output[11] == 0)
        return (nts::UNDEFINED);
    if (inputs[11].compute(output[11]) == nts::TRUE)
        return (nts::FALSE);
    else
        return (inputs[pin].compute(pin));
}

void Component_4040::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4040::check_input(std::size_t pin)
{
    if (pin == 10 || pin == 11)
        return (true);
    return (false);
}

bool Component_4040::check_output(std::size_t pin)
{
    if (pin >= 1 || pin <= 7 || pin >= 12 || pin <= 15)
        return (true);
    return (false);
}

void Component_4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}

#endif /* !COMPONENT_4040_HPP_ */
