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
}

Component_4008::~Component_4008()
{
}

nts::Tristate Component_4008::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin == 10) {
        if (inputs[6].compute(output[6]) == nts::TRUE
        ^ inputs[7].compute(output[7]) == nts::TRUE)
            if (inputs[9].compute(output[9]) == nts::FALSE)
                return (nts::TRUE);
            else
                return (nts::FALSE);
        }
    if (pin == 11) {
        if (inputs[4].compute(output[4]) == nts::TRUE
        ^ inputs[5].compute(output[5]) == nts::TRUE)
            if (this->compute(output[10]) == nts::FALSE)
                return (nts::TRUE);
            else
                return (nts::FALSE);
    }
    if (pin == 12) {
        if (inputs[2].compute(output[2]) == nts::TRUE
        ^ inputs[3].compute(output[3]) == nts::TRUE)
            if (this->compute(output[11]) == nts::FALSE)
                return (nts::TRUE);
            else
                return (nts::FALSE);
    }
    if (pin == 13) {
        if (inputs[1].compute(output[1]) == nts::TRUE
        ^ inputs[15].compute(output[15]) == nts::TRUE)
            if (this->compute(output[12]) == nts::FALSE)
                return (nts::TRUE);
            else
                return (nts::FALSE);
    }
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
