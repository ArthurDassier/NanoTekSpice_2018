/*
** EPITECH PROJECT, 2019
** Component_2716.h
** File description:
** 2716
*/

#ifndef COMPONENT_2716_HPP_
	#define COMPONENT_2716_HPP_

#include "Component.hpp"

class Component_2716 : public Component
{
    public:
        Component_2716(std::string);
        ~Component_2716();

        // Member
        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;

        bool check_input(std::size_t);
        bool check_output(std::size_t);
};

#endif /* !COMPONENT_2716_HPP_ */
