/*
** EPITECH PROJECT, 2019
** Input.hpp
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

#include "IComponent.hpp"

class Input : public nts::ISpecialComponent {
    public:
        Input(std::string);
        ~Input();

        nts::Tristate getValue() const noexcept;
    private:
        std::string _name;
        nts::Tristate _value;
};

Input::Input(std::string name) :
    _name(name)
{
}

Input::~Input()
{
}

nts::Tristate Input::getValue() const noexcept
{
    return (_value);
}

#endif /* !INPUT_HPP_ */
