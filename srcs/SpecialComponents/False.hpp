/*
** EPITECH PROJECT, 2019
** False.hpp
** File description:
** False
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

#include "IComponent.hpp"

class False : public nts::IComponent {
    public:
        False(std::string);
        ~False();

        nts::Tristate compute() const noexcept;
        void dump() const noexcept;
    private:
        std::string _name;
        nts::Tristate _value;
};

False::False(std::string name) :
    _name(name)
{
    _value = nts::FALSE;
}

False::~False()
{
}

nts::Tristate False::compute() const noexcept
{
    return (_value);
}

void False::dump() const noexcept
{
    std::cout << _name << std::endl;
}

#endif /* !FALSE_HPP_ */
