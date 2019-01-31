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

True::True(std::string name) :
    _name(name)
{
}

True::~True()
{
}

nts::Tristate True::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    return (nts::TRUE);
}

void True::dump() const noexcept
{
    std::cout << _name << std::endl;
}

bool True::check_input(std::size_t pin)
{
    if (pin == 1)
        return (true);
    return (false);
}

bool True::check_output(std::size_t pin)
{
    return (false);
}

void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}

#endif /* !TRUE_HPP_ */
