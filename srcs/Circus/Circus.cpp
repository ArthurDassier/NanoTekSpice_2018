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
            it = my_circus.erase(it);
            break;
        }
    }
}

void Circus::display()
{
    for (auto &it : results)
        std::cout << it << std::endl;
}

void Circus::lets_run()
{
    results.clear();
    for (auto &it : my_circus) {
        if (it->getType() == "output")
            results.push_back(std::string(it->getName()) + std::string("=") + std::to_string(it->compute()));
    }
}
