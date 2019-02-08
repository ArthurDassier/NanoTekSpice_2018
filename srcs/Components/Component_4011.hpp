/*
** EPITECH PROJECT, 2019
** Component_4011.h
** File description:
** 4011
*/

#ifndef COMPONENT_4011_HPP_
	#define COMPONENT_4011_HPP_

#include "Component.hpp"

class Component_4011 : public Component
{
    public:
        Component_4011(std::string);
        ~Component_4011();

        // Members
        nts::Tristate compute(std::size_t pin = 1);
        nts::Tristate operand(std::size_t, std::size_t);

        bool check_input(std::size_t);
        bool check_output(std::size_t);
};

#endif /* !COMPONENT_4011_HPP_ */
