/*
** EPITECH PROJECT, 2019
** Clock.hpp
** File description:
** clock
*/

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_

#include "IComponent.hpp"

class Clock : public nts::IComponent {
    public:
        Clock(std::string);
        ~Clock();

        nts::Tristate getValue() const noexcept;
        void dump() const noexcept;
    private:
        std::string _name;
        nts::Tristate _value;
};

Clock::Clock(std::string name) :
    _name(name)
{
}

Clock::~Clock()
{
}

nts::Tristate Clock::getValue() const noexcept
{
    return (_value);
}

void Clock::dump() const noexcept
{
    std::cout << _name << std::endl;
}

#endif /* !CLOCK_HPP_ */
