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

Input::Input(std::string name) :
    _name(name)
{
}

Input::~Input()
{
}

nts::Tristate Input::compute(std::size_t pin = 1)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    std::cout << inputs[1].compute(output[1]) << std::endl;
    return (inputs[1].compute(output[1]));
}

void Input::dump() const
{
    std::cout << _name << std::endl;
}

bool Input::check_input(std::size_t pin)
{
    return (false);
}

bool Input::check_output(std::size_t pin)
{
    if (pin == 1)
        return (true);
    return (false);
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (check_input(pin)) {
        inputs[pin] = other;
        output[pin] = otherPin;
    }
}

#endif /* !INPUT_HPP_ */
