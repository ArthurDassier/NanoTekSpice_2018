/*
** EPITECH PROJECT, 2019
** Component_4001.h
** File description:
** 4001
*/

#ifndef COMPONENT_4001_HPP_
	#define COMPONENT_4001_HPP_

#include "Component.hpp"

class Component_4001 : public Component
{
    public:
        Component_4001(std::string);
        ~Component_4001();

        // Members
        nts::Tristate compute(std::size_t pin = 1);
        nts::Tristate operand(std::size_t, std::size_t);
        void dump() const;

        bool check_input(std::size_t);
        bool check_output(std::size_t);
};

#endif /* !COMPONENT_4001_HPP_ */
