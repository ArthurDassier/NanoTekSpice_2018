/*
** EPITECH PROJECT, 2019
** Component_4094.h
** File description:
** 4094
*/

#ifndef COMPONENT_4094_HPP_
	#define COMPONENT_4094_HPP_

#include "Component.hpp"

class Component_4094 : public Component
{
    public:
        Component_4094(std::string);
        ~Component_4094();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;

        bool check_input(std::size_t);
        bool check_output(std::size_t);
};

#endif /* !COMPONENT_4094_HPP_ */
