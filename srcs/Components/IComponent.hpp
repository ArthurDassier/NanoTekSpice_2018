/*
** EPITECH PROJECT, 2019
** IComponent.h
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
	#define ICOMPONENT_HPP_

#include <iostream>
#include <string>
#include <vector>

namespace nts
{
    enum  Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void dump() const = 0;
            virtual void setLink(std::size_t, nts::IComponent &, std::size_t) = 0;
            virtual bool check_input(std::size_t) = 0;
            virtual bool check_output(std::size_t) = 0;
            virtual std::string getName() const = 0;
            virtual std::string getType() const = 0;
    };

    typedef struct links_s
    {
        nts::IComponent *cmp;
        std::size_t output;
    } link_t;
};

#endif /* !ICOMPONENT_HPP_ */
