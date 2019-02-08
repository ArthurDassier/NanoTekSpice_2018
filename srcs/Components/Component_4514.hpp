/*
** EPITECH PROJECT, 2019
** Component_4514.h
** File description:
** 4514
*/

#ifndef COMPONENT_4514_HPP_
	#define COMPONENT_4514_HPP_

#include "Component.hpp"

class Component_4514 : public Component
{
    public:
        Component_4514(std::string name);
        ~Component_4514();

        nts::Tristate compute(std::size_t pin = 1);
        nts::Tristate operand(std::size_t, std::size_t);

        bool check_input(std::size_t);
        bool check_output(std::size_t);
};

#endif /* !COMPONENT_4514_HPP_ */
