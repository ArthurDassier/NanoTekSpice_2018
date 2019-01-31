/*
** EPITECH PROJECT, 2019
** Component_4008.h
** File description:
** 4008
*/

#ifndef COMPONENT_4008_HPP_
	#define COMPONENT_4008_HPP_

#include "IComponent.hpp"

class Component_4008 : public nts::IComponent
{
    public:
        Component_4008(std::string);
        ~Component_4008();

        // Members
        nts::Tristate compute(std::size_t pin = 1);
        nts::Tristate operand(std::size_t, std::size_t, std::size_t);
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

Component_4008::Component_4008(std::string name) :
    _name(name)
{
    for(size_t i = 1; i != 15; ++i)
        output[i] = 0;
}

Component_4008::~Component_4008()
{
}

nts::Tristate Component_4008::operand(std::size_t in1, std::size_t in2, std::size_t in3)
{
    if (output[in1] == 0 || output[in2] == 0)
        return (nts::UNDEFINED);
    if (inputs[in1].compute(output[in1]) == nts::TRUE
    ^ inputs[in2].compute(output[in2]) == nts::TRUE) {
        if (inputs[in3].compute(output[in3]) == nts::FALSE)
            return (nts::TRUE);
        else
            return (nts::FALSE);
    }
    return (nts::UNDEFINED);
}

nts::Tristate Component_4008::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin == 10)
        return (operand(6, 7, 9));
    if (pin == 11)
        return (operand(4, 5, this->compute[10]));
    if (pin == 12)
        return (operand(2, 3, this->compute[11]));
    if (pin == 13)
        return (operand(1, 15, this->compute[12]));
    return (nts::UNDEFINED);
}

void Component_4008::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4008::check_input(std::size_t pin)
{
    if (pin >= 1 && pin <= 7 || pin == 9 || pin == 15)
        return (true);
    return (false);
}

bool Component_4008::check_output(std::size_t pin)
{
    if (pin == 10 || pin == 11 || pin == 12 || pin == 13)
        return (true);
    return (false);
}

void Component_4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}

#endif /* !COMPONENT_4008_HPP_ */
