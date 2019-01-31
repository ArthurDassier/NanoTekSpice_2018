#include "Parser.hpp"

namespace parser
{
    Parser::Parser(std::string name/*, Circus my_circus*/) : filename(name)/*, circus(my_circus)*/
    {
    }

    Parser::~Parser()
    {
    }

    bool Parser::CheckMainError(std::vector<std::string> &stock)
    {
        bool link = false, chipset = false;

        for (auto &it : (stock)) {
            if (it.data() == std::string(".links:"))
                link = true;
            else if (it.data() == std::string(".chipsets:"))
                chipset = true;
        }
        if (link && chipset)
            return true;
        return false;
    }

    bool Parser::ParseChipset(std::vector<std::string> &stock)
    {
        bool link = false, chipset = false;

        for (auto &it : (stock)) {
            if (it.data() == std::string(".links:"))
                link = true;
            else if (it.data() == std::string(".chipsets:"))
                chipset = true;
        }
        if (link && chipset)
            return true;
        return false;
    }

    void Parser::LetsParse()
    {
        std::ifstream file;
        std::string tmp;
        std::vector<std::string> stock;

        file.open(filename);
        if (!file.is_open()) {
            std::cerr << "Error" << std::endl;
            return; //throw execption
        }
        while (!file.eof()) {
            getline(file, tmp);
            stock.push_back(tmp);
        }
        if (!CheckMainError(stock))
            std::cerr << "Invalid Circut" << std::endl;
        if (!ParseChipset(stock))
            std::cerr << "Invalid chipset" << std::endl;
    }
}
