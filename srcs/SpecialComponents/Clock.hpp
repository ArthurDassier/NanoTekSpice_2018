/*
** EPITECH PROJECT, 2019
** Clock.h
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_

#include "IComponent.hpp"

class Clock : public nts::IComponent
{
    public:
        Clock(std::string);
        ~Clock();

        // Members
        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        void setClock(nts::Tristate);
        std::string getName() const;
        std::string getType() const;

        bool check_input(std::size_t);
        bool check_output(std::size_t);

    private:
        const std::string _name;
        const std::string _type;
        nts::Tristate _input;
};

#endif /* !CLOCK_HPP_ */
