/*
** EPITECH PROJECT, 2019
** Output.hpp
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

#include "IComponent.hpp"

class Output : public nts::IComponent {
    public:
        Output(std::string);
        ~Output();

        // Members
        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        std::string getName();

        bool check_input(std::size_t);
        bool check_output(std::size_t);

    private:
        std::string _name;
        nts::IComponent *cmp;
        std::size_t output;
};

#endif /* !OUTPUT_HPP_ */
