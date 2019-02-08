/*
** EPITECH PROJECT, 2019
** Input.h
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

#include "IComponent.hpp"

class Input : public nts::IComponent
{
    public:
        Input(std::string);
        ~Input();

        // Members
        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        void setInput(nts::Tristate);
        std::string getName() const;
        std::string getType() const;

        bool check_input(std::size_t);
        bool check_output(std::size_t);

    private:
        const std::string _name;
        const std::string _type;
        nts::Tristate _input;
};

#endif /* !INPUT_HPP_ */
