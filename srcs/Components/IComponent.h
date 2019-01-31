/*
** EPITECH PROJECT, 2019
** IComponent.h
** File description:
** IComponent
*/

#ifndef ICOMPONENT_H_
	#define ICOMPONENT_H_

class IComponent
{
    public:
        IComponent(/* args */);
        ~IComponent();

        virtual ~IComponent() = default
        virtual nts::Tristate compute(std::size_t pin = 1) = 0;
        virtual void dump() const = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    private:
        /* data */
};

#endif /* !ICOMPONENT_H_ */
