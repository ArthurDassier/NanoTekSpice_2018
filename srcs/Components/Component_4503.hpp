/*
** EPITECH PROJECT, 2019
** Component_4503.h
** File description:
** 4503
*/

#ifndef COMPONENT_4503_HPP_
	#define COMPONENT_4503_HPP_

#include "IComponent.hpp"

class Component_4503 : public nts::IComponent
{
    public:
        Component_4503(std::string);
        ~Component_4503();

        // Members
        nts::Tristate compute(std::size_t pin = 1);
        nts::Tristate operand(std::size_t, std::size_t);
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

Component_4503::Component_4503(std::string name) :
    _name(name)
{
    for(size_t i = 1; i != 16; ++i)
        output[i] = 0;
}

Component_4503::~Component_4503()
{
}

nts::Tristate Component_4503::operand(std::size_t in1, std::size_t in2)
{
    if (output[in1] == 0 || output[in2] == 0)
        return (nts::UNDEFINED);
    if (inputs[in1].compute(output[in1]) == nts::FALSE)
        return (nts::UNDEFINED);
    if (inputs[in1].compute(output[in1]) == nts::TRUE
    || !(inputs[in2].compute(output[in2]) == nts::TRUE))
        return (nts::TRUE);
    return (nts::FALSE);
}

nts::Tristate Component_4503::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin == 3)
        return (operand(1, 2));
    if (pin == 5)
        return (operand(1, 4));
    if (pin == 7)
        return (operand(1, 6));
    if (pin == 9)
        return (operand(1, 10));
    if (pin == 11)
        return (operand(12, 15));
    if (pin == 13)
        return (operand(14, 15));
    return (nts::FALSE);
}

void Component_4503::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4503::check_input(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 4 || pin == 6
    || pin == 10 || pin == 12 || pin == 14 || pin == 15)
        return (true);
    return (false);
}

bool Component_4503::check_output(std::size_t pin)
{
    if (pin == 3 || pin == 5 || pin == 7 || pin == 9 || pin == 11 || pin == 13)
        return (true);
    return (false);
}

void Component_4503::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}


#endif /* !COMPONENT_4503_HPP_ */
