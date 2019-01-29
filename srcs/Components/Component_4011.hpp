/*
** EPITECH PROJECT, 2019
** Component_4011.h
** File description:
** 4011
*/

#ifndef COMPONENT_4011_HPP_
	#define COMPONENT_4011_HPP_

#include "IComponent.hpp"

class Component_4011 : public nts::IComponent
{
    public:
        Component_4011(std::string);
        ~Component_4011();

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

Component_4011::Component_4011(std::string name) :
    _name(name)
{
}

Component_4011::~Component_4011()
{
}

nts::Tristate Component_4011::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin == 3) {
        if (!(inputs[1].compute(output[1]) == nts::TRUE
        && inputs[2].compute(output[2]) == nts::TRUE))
            return (nts::TRUE);
    }
    if (pin == 4) {
        if (!(inputs[5].compute(output[5]) == nts::TRUE
        && inputs[6].compute(output[6]) == nts::TRUE))
            return (nts::TRUE);
    }
    if (pin == 10) {
        if (!(inputs[9].compute(output[9]) == nts::TRUE
        && inputs[8].compute(output[8]) == nts::TRUE))
            return (nts::TRUE);
    }
    if (pin == 11) {
        if (!(inputs[12].compute(output[12]) == nts::TRUE
        && inputs[13].compute(output[13]) == nts::TRUE))
            return (nts::TRUE);
    }
    return (nts::FALSE);
}

void Component_4011::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4011::check_input(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 5 || pin == 6 || pin == 8
    || pin == 9 || pin == 12  || pin == 13)
        return (true);
    return (false);
}

bool Component_4011::check_output(std::size_t pin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
        return (true);
    return (false);
}

void Component_4011::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}

#endif /* !COMPONENT_4011_HPP_ */
