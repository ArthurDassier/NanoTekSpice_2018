#include "Circus.hpp"
#include "Factory.hpp"
#include "Parser.hpp"
#include "Component.hpp"

int main(int ac, char **av)
{
    Circus circus;
    Factory factory;
    parser::Parser parser(av[1], circus, factory);
    parser.LetsParse();
    std::vector<nts::IComponent *> tmp_circus = circus.getCircus();
    circus.lets_run();
    return (0);
}
