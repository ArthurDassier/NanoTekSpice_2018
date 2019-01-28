/*
** EPITECH PROJECT, 2019
** False.hpp
** File description:
** False
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

#include "ISpecialComponent.hpp"

class False : public ISpecialComponent {
    public:
        False(std::string);
        ~False();

        ISpecialComponent::Tristate getValue() const noexcept;
    private:
        std::string _name;
        ISpecialComponent::Tristate _value;
};

False::False(std::string name) :
    _name(name)
{
}

False::~False()
{
}

ISpecialComponent::Tristate False::getValue() const noexcept
{
    return (_value);
}

#endif /* !FALSE_HPP_ */
