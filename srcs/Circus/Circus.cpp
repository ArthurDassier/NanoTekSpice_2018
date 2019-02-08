/*
** EPITECH PROJECT, 2019
** Circus.cpp
** File description:
** Circus
*/

#include "Circus.hpp"

Circus::Circus()
{
}

Circus::~Circus()
{
}

void Circus::addComponent(nts::IComponent &obj)
{
    my_circus.push_back(&obj);
}

void Circus::removeComponent(std::string name)
{
    for(size_t i = 0; i < my_circus.size(); ++i) {
        if (my_circus[i]->getName() == name) {
            my_circus.erase(my_circus.begin() + i);
            break;
        }
    }
}

void Circus::lets_run()
{
    for(size_t i = 0; i < my_circus.size(); ++i) {
        if (my_circus[i]->getType() == "Output")
            std::cout << my_circus[i]->compute()<< std::endl;
    }
}

