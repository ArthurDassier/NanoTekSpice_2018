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
#include <memory>
#include "IComponent.hpp"

class Circus {
    public:
        Circus();
        ~Circus();

    void addComponent(nts::IComponent &obj);
    void removeComponent(std::string name);
    void run();

    private:
        std::vector<std::unique_ptr<IComponent>> my_circus;
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
