/*
** EPITECH PROJECT, 2019
** Component_4503.h
** File description:
** 4503
*/

#ifndef COMPONENT_4503_HPP_
	#define COMPONENT_4503_HPP_

#include "IComponent.hpp"

class Component_4503 : public nts::IComponent
{
    public:
        Component_4503(std::string);
        ~Component_4503();

        // Members
        nts::Tristate compute(std::size_t pin = 1);
        nts::Tristate operand(std::size_t, std::size_t);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

        bool check_input(std::size_t);
        bool check_output(std::size_t);

    private:
        std::string _name;
        std::vector<nts::link_t> _list;
};

#endif /* !COMPONENT_4503_HPP_ */