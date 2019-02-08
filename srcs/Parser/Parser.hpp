#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
// #include "Circus.hpp"
// #include "IComponent.hpp"
// #include "Factory.hpp"

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
        Parser(std::string name/*, Circus my_circus, Factory my_factory*/);
        ~Parser();
        void LetsParse();
    private:
        bool ParseFile(std::vector<std::string> &stock);
        bool ParseChipset(std::vector<std::string> &stock, std::string &it);
        bool ParseLink(std::vector<std::string> &stock, std::string &it);
        bool CheckMainError(std::vector<std::string> &stock);
        // Circus circus;
        // Factory factory;
        std::string filename;
    };
}

#endif