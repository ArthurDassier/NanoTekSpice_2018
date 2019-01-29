/*
** EPITECH PROJECT, 2019
** True.hpp
** File description:
** True
*/

#ifndef TRUE_HPP_
	#define TRUE_HPP_

#include "IComponent.hpp"

class True : public nts::IComponent {
    public:
        True(std::string);
        ~True();

        nts::Tristate getValue() const noexcept;
        void dump() const noexcept;
    private:
        std::string _name;
        nts::Tristate _value;
};

True::True(std::string name) :
    _name(name)
{
    _value = nts::TRUE;
}

True::~True()
{
}

nts::Tristate True::getValue() const noexcept
{
    return (_value);
}

void True::dump() const noexcept
{
    std::cout << _name << std::endl;
}

#endif /* !TRUE_HPP_ */
