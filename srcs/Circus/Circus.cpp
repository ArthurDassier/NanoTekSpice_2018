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
    for(auto it = my_circus.begin(); it != my_circus.end(); ++it) {
        if ((*it)->getName() == name) {
            std::cout << "ici" << std::endl;
            it = my_circus.erase(it);
            break;
        }
    }
}

void Circus::lets_run()
{
    std::cout << "Start Run !" << std::endl;
    for(auto &it : my_circus) {
        if (it->getType() == "output") {
            std::cout << it->getName() << std::endl;
            std::cout << it->compute()<< std::endl;
        }
    }
}
