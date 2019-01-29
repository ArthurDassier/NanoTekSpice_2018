/*
** EPITECH PROJECT, 2019
** Output.hpp
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

#include "IComponent.hpp"

class Output : public nts::IComponent {
    public:
        Output(std::string);
        ~Output();

        nts::Tristate getValue() const noexcept;
        void dump() const noexcept;
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

void Output::dump() const noexcept
{
    std::cout << _name << std::endl;
}

#endif /* !OUTPUT_HPP_ */
