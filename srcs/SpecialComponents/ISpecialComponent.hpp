/*
** EPITECH PROJECT, 2019
** ISpecialCOmponent.hpp
** File description:
** SpecialCOmponent
*/

#ifndef ISPECIALCOMPONENT_HPP_
	#define ISPECIALCOMPONENT_HPP_

#include <iostream>
#include <string>

class ISpecialComponent {
    public:
        enum  Tristate {
            UNDEFINED = (-true),
            TRUE = true ,
            FALSE = false
        };
        ~ISpecialComponent();
        virtual ~ISpecialComponent() = default;

        virtual Tristate getValue() const noexcept = 0;
};

#endif /* !ISPECIALCOMPONENT_HPP_ */
