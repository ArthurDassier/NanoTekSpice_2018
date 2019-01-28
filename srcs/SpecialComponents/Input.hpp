/*
** EPITECH PROJECT, 2019
** Input.hpp
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

#include "ISpecialComponent.hpp"

class Input : public ISpecialComponent {
    public:
        Input(std::string);
        ~Input();

        ISpecialComponent::Tristate getValue() const noexcept;
    private:
        std::string _name;
        ISpecialComponent::Tristate _value;
};

Input::Input(std::string name) :
    _name(name)
{
}

Input::~Input()
{
}

ISpecialComponent::Tristate Input::getValue() const noexcept
{
    return (_value);
}

#endif /* !INPUT_HPP_ */
