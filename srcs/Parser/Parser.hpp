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
    class Parser
    {
    public:
        Parser(std::string name/*, Circus my_circus*/);
        ~Parser();
        void LetsParse();
    private:
        bool ParseChipset(std::vector<std::string> &stock);
        bool CheckMainError(std::vector<std::string> &stock);
        // Circus circus;
        std::string filename;
    };
}

#endif
