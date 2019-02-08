/*
** EPITECH PROJECT, 2019
** Component_4512.h
** File description:
** 4512
*/

#ifndef COMPONENT_4512_HPP_
	#define COMPONENT_4512_HPP_

#include "Component.hpp"

class Component_4512 : public Component
{
    public:
        Component_4512(std::string);
        ~Component_4512();

        // Members
        nts::Tristate compute(std::size_t pin = 1);

        bool check_input(std::size_t);
        bool check_output(std::size_t);
};

#endif /* !COMPONENT_4512_HPP_ */