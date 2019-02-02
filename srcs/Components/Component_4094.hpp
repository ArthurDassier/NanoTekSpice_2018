/*
** EPITECH PROJECT, 2019
** Component_4094.h
** File description:
** 4094
*/

#ifndef COMPONENT_4094_HPP_
	#define COMPONENT_4094_HPP_

#include "IComponent.hpp"

class Component_4094 : public nts::IComponent
{
    public:
        Component_4094(std::string);
        ~Component_4094();

        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

        bool check_input(std::size_t);
        bool check_output(std::size_t);

    private:
        std::string _name;
        std::vector<nts::link_t> _list;
};

#endif /* !COMPONENT_4094_HPP_ */
