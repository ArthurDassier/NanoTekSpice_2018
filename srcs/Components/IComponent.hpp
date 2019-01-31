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

namespace nts
{
    enum  Tristate {
        UNDEFINED = (-true),
        TRUE = true ,
        FALSE = false
    };

    class IComponent
    {
        public:
            ~IComponent();
            virtual ~IComponent() = default;

            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void dump() const = 0;
            virtual void setLink(std::size_t, nts::IComponent &, std::size_t) = 0;
    };

};

#endif /* !ICOMPONENT_HPP_ */
