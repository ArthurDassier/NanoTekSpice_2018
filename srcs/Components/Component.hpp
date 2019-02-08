/*
** EPITECH PROJECT, 2019
** Component.hpp
** File description:
** COmponent
*/

#ifndef COMPONENT_HPP_
	#define COMPONENT_HPP_

#include "IComponent.hpp"

class Component : public nts::IComponent {
        public:
            Component();
            ~Component();

            // Members
            void setLink(std::size_t, nts::IComponent &, std::size_t);
            std::string getName() const;
            std::string getType() const;
            void dump() const;

        protected:
            std::string _name;
            std::string _type;
            std::vector<nts::link_t> _list;
    };

#endif /* !COMPONENT_HPP_ */
