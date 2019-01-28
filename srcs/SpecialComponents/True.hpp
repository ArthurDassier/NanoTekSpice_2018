/*
** EPITECH PROJECT, 2019
** True.hpp
** File description:
** True
*/

#ifndef TRUE_HPP_
	#define TRUE_HPP_

#include "ISpecialComponent.hpp"

class True : public ISpecialComponent {
    public:
        True(std::string);
        ~True();

        ISpecialComponent::Tristate getValue() const noexcept;
    private:
        std::string _name;
        ISpecialComponent::Tristate _value;
};

True::True(std::string name) :
    _name(name)
{
}

True::~True()
{
}

ISpecialComponent::Tristate True::getValue() const noexcept
{
    return (_value);
}

#endif /* !TRUE_HPP_ */
