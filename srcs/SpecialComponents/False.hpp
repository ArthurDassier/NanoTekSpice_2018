/*
** EPITECH PROJECT, 2019
** False.hpp
** File description:
** False
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

#include "IComponent.hpp"

class False : public nts::IComponent {
    public:
        False(std::string);
        ~False();

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

False::False(std::string name) :
    _name(name)
{
}

False::~False()
{
}

nts::Tristate False::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    return (nts::FALSE);
}

void False::dump() const noexcept
{
    std::cout << _name << std::endl;
}

bool False::check_input(std::size_t pin)
{
    if (pin == 1)
        return (true);
    return (false);
}

bool False::check_output(std::size_t pin)
{
    return (false);
}

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}

#endif /* !FALSE_HPP_ */
