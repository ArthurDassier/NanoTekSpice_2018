/*
** EPITECH PROJECT, 2019
** Component_2716.h
** File description:
** 2716
*/

#ifndef COMPONENT_2716_HPP_
	#define COMPONENT_2716_HPP_

#include "IComponent.hpp"

class Component_2716 : public nts::IComponent
{
    public:
        Component_2716(std::string);
        ~Component_2716();

        // Member
        nts::Tristate compute(std::size_t pin = 1);
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

#endif /* !COMPONENT_2716_HPP_ */
