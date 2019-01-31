/*
** EPITECH PROJECT, 2019
** Clock.hpp
** File description:
** clock
*/

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_

#include "ISpecialComponent.hpp"

class Clock : public ISpecialComponent {
    public:
        Clock(std::string);
        ~Clock();

        ISpecialComponent::Tristate getValue() const noexcept;
    private:
        std::string _name;
        ISpecialComponent::Tristate _value;
};

Clock::Clock(std::string name) :
    _name(name)
{
}

Clock::~Clock()
{
}

ISpecialComponent::Tristate Clock::getValue() const noexcept
{
    return (_value);
}

#endif /* !CLOCK_HPP_ */
