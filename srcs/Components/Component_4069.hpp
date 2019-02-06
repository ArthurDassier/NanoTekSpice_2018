/*
** EPITECH PROJECT, 2019
** Component_4069.h
** File description:
** 4069
*/

#ifndef COMPONENT_4069_HPP_
	#define COMPONENT_4069_HPP_

#include "Component.hpp"

class Component_4069 : public Component
{
    public:
        Component_4069(std::string);
        ~Component_4069();

        // Members
        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;

        bool check_input(std::size_t);
        bool check_output(std::size_t);
};

#endif /* !COMPONENT_4069_HPP_ */
