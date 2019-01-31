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

        // Members
        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

        bool check_input(std::size_t);
        bool check_output(std::size_t);

    private:
        std::string _name;
        std::unordered_map<std::size_t, nts::IComponent &> inputs;
        std::unordered_map<std::size_t, std::size_t> output;
};

Output::Output(std::string name) :
    _name(name)
{
}

Output::~Output()
{
}

nts::Tristate Output::compute(std::size_t pin = 1)
{
    std::cout << inputs[1].compute(output[1]) << std::endl;
    return (inputs[1].compute(output[1]));
}

void Output::dump() const
{
    std::cout << _name << std::endl;
}

bool Output::check_input(std::size_t pin)
{
    if (pin == 1)
        return (true);
    return (false);
}

bool Output::check_output(std::size_t pin)
{
    return (false);
}

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}

#endif /* !OUTPUT_HPP_ */
