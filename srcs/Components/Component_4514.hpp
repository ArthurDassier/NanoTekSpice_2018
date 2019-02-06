/*
** EPITECH PROJECT, 2019
** Component_4514.h
** File description:
** 4514
*/

#ifndef COMPONENT_4514_HPP_
	#define COMPONENT_4514_HPP_

#include "IComponent.hpp"

class Component_4514 : public nts::IComponent
{
    public:
        Component_4514(std::string name);
        ~Component_4514();

        nts::Tristate compute(std::size_t pin = 1);
        nts::Tristate operand(std::size_t, std::size_t);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName() const;
        std::string getType() const;

        bool check_input(std::size_t);
        bool check_output(std::size_t);

    private:
        const std::string _name;
        const std::string _type;
        std::vector<nts::link_t> _list;
};

#endif /* !COMPONENT_4514_HPP_ */
