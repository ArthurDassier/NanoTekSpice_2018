/*
** EPITECH PROJECT, 2019
** Component_4514.h
** File description:
** 4514
*/

#ifndef COMPONENT_4514_HPP_
	#define COMPONENT_4514_HPP_

#include "IComponent.hpp"

class Component_4514 : public nts::IComponent
{
    public:
        Component_4514(std::string name);
        ~Component_4514();

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

Component_4514::Component_4514(std::string name) :
    _name(name)
{
    for(size_t i = 1; i != 24; ++i)
        output[i] = 0;
}

Component_4514::~Component_4514()
{
}

nts::Tristate Component_4514::operand(std::size_t in1, std::size_t in2)
{
//
}

nts::Tristate Component_4514::compute(std::size_t pin = 1)
{
    int a = 1;
    int b = 2;
    int c = 4;
    int d = 8;
    int res = 0;

    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (inputs[1].compute(output[1]) == nts::TRUE)
        res += a;
    if (inputs[3].compute(output[3]) == nts::TRUE)
        res += b;
    if (inputs[21].compute(output[21]) == nts::TRUE)
        res += c;
    if (inputs[22].compute(output[22]) == nts::TRUE)
        res += d;
    if (pin <= 11) {
        if ((res + 4) == pin && inputs[23].compute(output[23]) == nts::FALSE)
            return (nts::TRUE);
        if ((res + 4) == pin && inputs[23].compute(output[23]) == nts::TRUE)
            return (nts::FALSE);
    }
    if (pin >= 13) {
        if ((res + 5) == pin && inputs[23].compute(output[23]) == nts::FALSE)
            return (nts::TRUE);
        if ((res + 5) == pin && inputs[23].compute(output[23]) == nts::TRUE)
            return (nts::FALSE);
    }
    return (nts::UNDEFINED);
}

void Component_4514::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4514::check_input(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 3 || pin == 21
    || pin == 22 || pin == 23)
        return (true);
    return (false);
}

bool Component_4514::check_output(std::size_t pin)
{
    if ((pin >= 4 && pin <= 11) || (pin >= 13 && pin <= 20))
        return (true);
    return (false);
}

void Component_4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}


#endif /* !COMPONENT_4514_HPP_ */
