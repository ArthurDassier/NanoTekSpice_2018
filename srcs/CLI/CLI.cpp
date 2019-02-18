/*
** EPITECH PROJECT, 2019
** CLI.cpp
** File description:
** CLI
*/

#include "CLI.hpp"

CLI::CLI(Circus &my_circus) : circus(my_circus)
{

}

CLI::~CLI()
{

}

void CLI::start(void)
{
    std::string line;
    std::string name_input;
    std::string value_input;
    size_t tmp = 0;
    std::vector<nts::IComponent *> tmp_circus = circus.getCircus();

    while (1) {
        std::cout << "> ";
        if (!(getline(std::cin, line)))
            return;
        if (line == "exit")
            return;
        else if (line == "simulate")
            circus.lets_run();
        else if (line == "display")
            circus.display();
        else {
            if ((tmp = line.find("=")) == std::string::npos)
                continue;
            name_input = line.substr(0, tmp);
            value_input = line.substr(tmp + 1, line.size() - tmp);
            for (auto &it : tmp_circus) {
                if (it->getName() == name_input)
                    static_cast<Input*>(it)->setInput(static_cast<nts::Tristate>(std::stoi(value_input)));
            }
        }
    }
}
