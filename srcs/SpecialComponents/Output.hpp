/*
** EPITECH PROJECT, 2019
** Output.hpp
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

#include "ISpecialComponent.hpp"

class Output : public ISpecialComponent {
    public:
        Output(std::string);
        ~Output();

        ISpecialComponent::Tristate getValue() const noexcept;
    private:
        std::string _name;
        ISpecialComponent::Tristate _value;
};

Output::Output(std::string name) :
    _name(name)
{
}

Output::~Output()
{
}

ISpecialComponent::Tristate Output::getValue() const noexcept
{
    return (_value);
}

#endif /* !OUTPUT_HPP_ */
