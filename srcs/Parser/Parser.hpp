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
        bool BuildLink(std::string pin_male, std::string pin_fem, nts::IComponent *it, nts::IComponent *it2);
        void FindPinComponentToLink(std::string &it,std::string &male, std::string &pin_male, std::string &fem, std::string &pin_fem);
        bool ParseChipsetFindSpeComp(std::string &it);
        void FindComponentToCreat(std::string &it, std::string &tmp, std::string &type);
        bool ParseChipsetFindComp(std::string &it);
        void SaveFile(std::vector<std::string> &stock);
        void FindTypeComponentToCreat(std::string &it, std::string &tmp, std::string &type);
        void FindNameComponentToCreat(std::string &it, std::string &tmp, std::string &type);
        void FinalCheck();
    private:
        Circus &_circus;
        Factory &factory;
        std::string filename;
    };
}

#endif
