/*
** EPITECH PROJECT, 2019
** False.hpp
** File description:
** False
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

#include "IComponent.hpp"

class False : public nts::ISpecialComponent {
    public:
        False(std::string);
        ~False();

        nts::Tristate getValue() const noexcept;
    private:
        std::string _name;
        nts::Tristate _value;
};

False::False(std::string name) :
    _name(name)
{
}

False::~False()
{
}

nts::Tristate False::getValue() const noexcept
{
    return (_value);
}

#endif /* !FALSE_HPP_ */
