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
#include "Input.hpp"
#include "Clock.hpp"
#include "error.hpp"

class Circus {
    public:
        Circus();
        ~Circus();

        void addComponent(nts::IComponent &obj);
        void removeComponent(std::string name);
        std::vector<nts::IComponent *> getCircus() const;
        void lets_run();
        void display();

    private:
        std::vector<nts::IComponent *> my_circus;
        std::vector<std::string> results;
};

#endif /* !CIRCUS_HPP_ */
