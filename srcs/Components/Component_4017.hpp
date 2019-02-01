/*
** EPITECH PROJECT, 2019
** Component_4017.h
** File description:
** 4017
*/

#ifndef COMPONENT_4017_HPP_
	#define COMPONENT_4017_HPP_

#include "IComponent.hpp"

class Component_4017 : public nts::IComponent
{
    public:
        Component_4017(std::string);
        ~Component_4017();

        // Members
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

#endif /* !COMPONENT_4017_HPP_ */
