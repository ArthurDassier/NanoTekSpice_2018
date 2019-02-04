/*
** EPITECH PROJECT, 2019
** False.hpp
** File description:
** False
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

#include "IComponent.hpp"

class False : public nts::IComponent {
    public:
        False(std::string);
        ~False();

        // Members
        nts::Tristate compute(std::size_t);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

        bool check_input(std::size_t);
        bool check_output(std::size_t);

    private:
        std::string _name;
};

#endif /* !FALSE_HPP_ */
