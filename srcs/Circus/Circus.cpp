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

std::vector<nts::IComponent *> Circus::getCircus() const
{
    return (my_circus);
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
    std::cout << "Start Run !" << std::endl;
    for(size_t i = 0; i < my_circus.size(); ++i) {
        if (my_circus[i]->getType() == "Output") {
            std::cout << my_circus[i]->getName() << std::endl;
            std::cout << my_circus[i]->compute()<< std::endl;
        }
    }
}
