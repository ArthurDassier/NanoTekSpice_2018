/*
** EPITECH PROJECT, 2019
** True.hpp
** File description:
** True
*/

#ifndef TRUE_HPP_
	#define TRUE_HPP_

#include "IComponent.hpp"

class True : public nts::ISpecialComponent {
    public:
        True(std::string);
        ~True();

        nts::Tristate getValue() const noexcept;
    private:
        std::string _name;
        nts::Tristate _value;
};

True::True(std::string name) :
    _name(name)
{
}

True::~True()
{
}

nts::Tristate True::getValue() const noexcept
{
    return (_value);
}

#endif /* !TRUE_HPP_ */
