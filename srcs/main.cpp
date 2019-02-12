#include "Circus.hpp"
#include "Factory.hpp"
#include "Parser.hpp"
#include "Component.hpp"
#include "CLI.hpp"

int main(int ac, char **av)
{
    if (ac <= 1)
        return (84);
    Circus circus;
    Factory factory;
    CLI my_CLI(circus);
    std::string name_input;
    std::string value_input;
    size_t tmp = 0;
    parser::Parser parser(av[1], circus, factory);
    parser.LetsParse();
    std::vector<nts::IComponent *> tmp_circus = circus.getCircus();

    if (ac > 1) {
        for (int i = 2; i < ac; i++) {
            if ((tmp = std::string(av[i]).find("=")) == std::string::npos)
                return (84);
            name_input = std::string(av[i]).substr(0, tmp);
            value_input = std::string(av[i]).substr(tmp + 1, std::string(av[i]).size() - tmp);
            for (auto &it : tmp_circus) {
                if (it->getName() == name_input)
                    static_cast<Input*>(it)->setInput(static_cast<nts::Tristate>(std::stoi(value_input)));
            }
        }
    }
    circus.lets_run();
    circus.display();
    my_CLI.start();
    return (0);
}
