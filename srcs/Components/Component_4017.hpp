/*
** EPITECH PROJECT, 2019
** Component_4017.h
** File description:
** 4017
*/

#ifndef COMPONENT_4017_HPP_
	#define COMPONENT_4017_HPP_

#include "Component.hpp"

class Component_4017 : public Component
{
    public:
        Component_4017(std::string);
        ~Component_4017();

        // Members
        nts::Tristate compute(std::size_t pin = 1);

        bool check_input(std::size_t);
        bool check_output(std::size_t);
};

#endif /* !COMPONENT_4017_HPP_ */
