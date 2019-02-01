/*
** EPITECH PROJECT, 2019
** Input.hpp
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

#include "IComponent.hpp"

<<<<<<< HEAD
class Input : public nts::IComponent {
=======
class Input : public nts::ISpecialComponent {
>>>>>>> 25fbe6ec523bc6916e3442afbbee4091d9412f68
    public:
        Input(std::string);
        ~Input();

<<<<<<< HEAD
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
=======
        nts::Tristate getValue() const noexcept;
    private:
        std::string _name;
        nts::Tristate _value;
>>>>>>> 25fbe6ec523bc6916e3442afbbee4091d9412f68
};

Input::Input(std::string name) :
    _name(name)
{
}

Input::~Input()
{
}

<<<<<<< HEAD
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
=======
nts::Tristate Input::getValue() const noexcept
{
    return (_value);
>>>>>>> 25fbe6ec523bc6916e3442afbbee4091d9412f68
}

#endif /* !INPUT_HPP_ */
