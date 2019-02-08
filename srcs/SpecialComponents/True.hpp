/*
** EPITECH PROJECT, 2019
** True.hpp
** File description:
** True
*/

#ifndef TRUE_HPP_
	#define TRUE_HPP_

#include "IComponent.hpp"

class True : public nts::IComponent {
    public:
        True(std::string);
        ~True();

        // Members
        nts::Tristate compute(std::size_t);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName() const;
        std::string getType() const;

        bool check_input(std::size_t);
        bool check_output(std::size_t);

    private:
        const std::string _name;
        const std::string _type;
};

#endif /* !TRUE_HPP_ */
