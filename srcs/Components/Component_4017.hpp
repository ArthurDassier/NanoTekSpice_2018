/*
** EPITECH PROJECT, 2019
** Component_4017.h
** File description:
** 4017
*/

#ifndef COMPONENT_4017_HPP_
	#define COMPONENT_4017_HPP_

#include "IComponent.hpp"

class Component_4017 : public nts::IComponent
{
    public:
        Component_4017(std::string);
        ~Component_4017();

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

Component_4017::Component_4017(std::string name) :
    _name(name)
{
}

Component_4017::~Component_4017()
{
}

nts::Tristate Component_4017::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
}

void Component_4017::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4017::check_input(std::size_t pin)
{
    if (pin >= 1 && pin <= 7 || pin >= 9 && pin <= 11)
        return (true);
    return (false);
}

bool Component_4017::check_output(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 12 || pin == 13)
        return (true);
    return (false);
}

void Component_4017::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}


#endif /* !COMPONENT_4017_HPP_ */
