/*
** EPITECH PROJECT, 2019
** Component_4040.h
** File description:
** 4040
*/

#ifndef COMPONENT_4040_HPP_
	#define COMPONENT_4040_HPP_

#include "Component.hpp"

class Component_4040 : public Component
{
    public:
        Component_4040(std::string);
        ~Component_4040();

        nts::Tristate compute(std::size_t pin = 1);

        bool check_input(std::size_t);
        bool check_output(std::size_t);
};

#endif /* !COMPONENT_4040_HPP_ */
