/*
** EPITECH PROJECT, 2019
** Component_4001.h
** File description:
** 4001
*/

#ifndef COMPONENT_4001_HPP_
	#define COMPONENT_4001_HPP_

#include "IComponent.hpp"

class Component_4001 : public nts::IComponent
{
    public:
        Component_4001(std::string);
        ~Component_4001();

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

Component_4001::Component_4001(std::string name) :
    _name(name)
{
    for(size_t i = 1; i != 13; ++i)
        output[i] = 0;
}

Component_4001::~Component_4001()
{
}

nts::Tristate Component_4001::operand(std::size_t in1, std::size_t in2)
{
    if (output[in1] == 0 || output[in2] == 0)
        return (nts::UNDEFINED);
    if (inputs[in1].compute(output[in1]) == nts::TRUE
    || inputs[in2].compute(output[in2]) == nts::TRUE)
        return (nts::FALSE);
    else if (inputs[in1].compute(output[in1]) == nts::UNDEFINED
    || inputs[in2].compute(output[in2]) == nts::UNDEFINED)
        return (nts::UNDEFINED);
    else
        return (nts::TRUE);
}

nts::Tristate Component_4001::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin == 3)
        return (operand(1, 2));
    if (pin == 4)
        return (operand(5, 6));
    if (pin == 10)
        return (operand(8, 9));
    if (pin == 11)
        return (operand(12, 13));
    return (nts::UNDEFINED);
}

void Component_4001::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4001::check_input(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 5 || pin == 6 ||
    pin == 8 || pin == 9 || pin == 12 || pin == 13)
        return (true);
    return (false);
}

bool Component_4001::check_output(std::size_t pin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
        return (true);
    return (false);
}

void Component_4001::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}


#endif /* !COMPONENT_4001_HPP_ */
