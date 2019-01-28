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

    std::vector<&nts::IComponent> my_circus;
    void addComponent(nts::IComponent &obj);
    void removeComponent(std::string name);
    void run();

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

void Circus::run()
{
}

#endif /* !CIRCUS_HPP_ */
