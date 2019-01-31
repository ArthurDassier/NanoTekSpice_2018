/*
** EPITECH PROJECT, 2019
** Output.hpp
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

#include "IComponent.hpp"

class Output : public nts::ISpecialComponent {
    public:
        Output(std::string);
        ~Output();

        nts::Tristate getValue() const noexcept;
    private:
        std::string _name;
        nts::Tristate _value;
};

Output::Output(std::string name) :
    _name(name)
{
}

Output::~Output()
{
}

nts::Tristate Output::getValue() const noexcept
{
    return (_value);
}

#endif /* !OUTPUT_HPP_ */
