/*
** EPITECH PROJECT, 2019
** Input.hpp
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

#include "IComponent.hpp"

class Input : public nts::IComponent {
    public:
        Input(std::string);
        ~Input();

        nts::Tristate getValue() const noexcept;
        void dump() const noexcept;
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

void Input::dump() const noexcept
{
    std::cout << _name << std::endl;
}

#endif /* !INPUT_HPP_ */
