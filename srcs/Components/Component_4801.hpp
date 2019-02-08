/*
** EPITECH PROJECT, 2019
** Component_4801.h
** File description:
** 4801
*/

#ifndef COMPONENT_4801_HPP_
	#define COMPONENT_4801_HPP_

#include "Component.hpp"

class Component_4801 : public Component
{
    public:
        Component_4801(std::string name);
        ~Component_4801();

        nts::Tristate compute(std::size_t pin = 1);

        bool check_input(std::size_t);
        bool check_output(std::size_t);
};

#endif /* !COMPONENT_4801_HPP_ */
