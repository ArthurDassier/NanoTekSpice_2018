/*
** EPITECH PROJECT, 2019
** Clock.hpp
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_

#include "IComponent.hpp"

class Clock : public nts::IComponent {
    public:
        Clock(std::string);
        ~Clock();

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

Clock::Clock(std::string name) :
    _name(name)
{
}

Clock::~Clock()
{
}

nts::Tristate Clock::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    std::cout << inputs[1].compute(output[1]) << std::endl;
    return (inputs[1].compute(output[1]));
}

void Clock::dump() const
{
    std::cout << _name << std::endl;
}

bool Clock::check_input(std::size_t pin)
{
    return (false);
}

bool Clock::check_output(std::size_t pin)
{
    if (pin == 1)
        return (true);
    return (false);
}

void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}

#endif /* !CLOCK_HPP_ */
