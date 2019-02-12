/*
** EPITECH PROJECT, 2019
** CLI.hpp
** File description:
** CLI
*/

#ifndef CLI_HPP_
#define CLI_HPP_

#include "Circus.hpp"
#include "Input.hpp"

class CLI
{
    public:
        CLI(Circus &my_circus);
        void start(void);
        ~CLI();

    private:
        Circus &circus;
};

#endif /* !CLOCK_HPP_ */
