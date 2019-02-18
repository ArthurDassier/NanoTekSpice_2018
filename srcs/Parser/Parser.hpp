#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include "Circus.hpp"
#include "Component.hpp"
#include "Clock.hpp"
#include "Input.hpp"
#include "False.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "Factory.hpp"
#include "error.hpp"

namespace parser
{
    enum mode_e {
        CHIPSET,
        LINK,
        UNKNOW
    };
    class Parser
    {
    public:
        Parser(std::string name, Circus &my_circus, Factory &my_factory);
        ~Parser();
        void LetsParse();
        bool ParseFile(std::vector<std::string> &stock);
        bool ParseChipset(std::string &it);
        bool ParseLink(std::string &it);
        bool CheckMainError(std::vector<std::string> &stock);
    private:
        Circus &_circus;
        Factory &factory;
        std::string filename;
    };
}

#endif
