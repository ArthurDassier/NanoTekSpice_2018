/*
** EPITECH PROJECT, 2019
** Circus.hpp
** File description:
** Circus
*/

#ifndef CIRCUS_HPP_
	#define CIRCUS_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "IComponent.hpp"

class Circus {
    public:
        Circus();
        ~Circus();

        void addComponent(nts::IComponent &obj);
        void removeComponent(std::string name);
        void lets_run();

    private:
        std::vector<nts::IComponent &> my_circus;
};

Circus::Circus()
{
}

Circus::~Circus()
{
}

void Circus::addComponent(nts::IComponent &obj)
{
}

void Circus::removeComponent(std::string name)
{
}

void Circus::lets_run()
{
}

#endif /* !CIRCUS_HPP_ */
