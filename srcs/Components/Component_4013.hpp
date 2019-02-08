/*
** EPITECH PROJECT, 2019
** Component_4013.h
** File description:
** 4013
*/

#ifndef COMPONENT_4013_HPP_
	#define COMPONENT_4013_HPP_

#include "Component.hpp"

class Component_4013 : public Component
{
    public:
        Component_4013(std::string);
        ~Component_4013();

        // Members
        nts::Tristate compute(std::size_t pin = 1);
    
        bool check_input(std::size_t);
        bool check_output(std::size_t);
};

#endif /* !COMPONENT_4013_HPP_ */
