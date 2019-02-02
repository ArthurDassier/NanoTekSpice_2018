#include "Parser.hpp"

namespace parser
{
    Parser::Parser(std::string name/*, Circus my_circus, Factory my_factory*/) : filename(name)/*, circus(my_circus), factory(my_factory)*/
    {
    }

    Parser::~Parser()
    {
    }

    bool Parser::CheckMainError(std::vector<std::string> &stock)
    {
        bool link = false, chipset = false;

        for (auto &it : (stock)) {
            if (it == std::string(".links:"))
                link = true;
            else if (it == std::string(".chipsets:"))
                chipset = true;
        }
        if (link && chipset)
            return true;
        return false;
    }

    bool Parser::ParseChipset(std::vector<std::string> &stock, std::string &it)
    {
        std::string SpeComp[5] = {"input", "clock", "false", "true", "output"};
        std::string tmp;
        std::string type;
        size_t ret;

        for (auto &it2 : SpeComp) {
            if (it.find(it2) != std::string::npos) {
                tmp = it.substr(it2.size());
                if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
                    tmp = tmp.substr(ret);
                if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
                    tmp = tmp.substr(ret);
                // factory(it2, tmp);
                // !\\ ajouter au circus vector
                std::cout << it2 << " find ! " << tmp << std::endl;
                break;
            }
        }
        if (std::isdigit(it[0])) {
            if ((ret = it.find_first_of(' ')) != std::string::npos)
                tmp = it.substr(0, ret);
            if ((ret = it.find_first_of('\t')) != std::string::npos)
                tmp = it.substr(0, ret);
            type = tmp;
            std::cout << "compenant find ! " << type << std::endl;
            tmp = it.substr(type.size());
            if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
                tmp = tmp.substr(ret);
            if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
                tmp = tmp.substr(ret);
            std::cout << "its name is ! " << tmp << std::endl;
            // factory(type, tmp);
            // !\\ ajouter au circus vector
        }
        return true;
    }

    bool Parser::ParseLink(std::vector<std::string> &stock, std::string &it)
    {
        size_t ret;
        size_t ret2;
        std::string male;
        std::string pin_male;
        std::string fem;
        std::string pin_fem;

        if ((ret = it.find(":")) != std::string::npos) {
            male = it.substr(0, ret);
            // std::cout << "male " << male << std::endl;
            if ((ret2 = it.find_first_of(" ")) != std::string::npos) {
                pin_male = it.substr(ret + 1, ret2 - (ret + 1));
                // std::cout << "pin_male " << pin_male << std::endl;
            }
            if ((ret2 = it.find_first_of("\t")) != std::string::npos) {
                pin_male = it.substr(ret + 1, ret2 - (ret + 1));
                // std::cout << "pin_male " << pin_male << std::endl;
            }
        }
        if ((ret = it.rfind(":")) != std::string::npos) {
            ret2 = it.rfind(" ");
            ret2 = it.rfind("\t");
            fem = it.substr(ret2 + 1, ret - (ret2 + 1));
            // std::cout << "fem : " << fem << std::endl;
            pin_fem = it.substr(ret + 1);
            // std::cout << "pin_fem : " << pin_fem << std::endl;
        }
        std::cout << "male " << male << "||" << " pin_male " << pin_male << "||" << " fem : " << fem << "||" << " pin_fem : " << pin_fem << std::endl;
        return true;
    }

    bool Parser::ParseFile(std::vector<std::string> &stock)
    {
        mode_e mode = UNKNOW;

        for (auto &it : stock) {
            if (it == std::string(".links:")) {
                mode = LINK;
                continue;
            }
            if (it == std::string(".chipsets:")) {
                mode = CHIPSET;
                continue;
            }
            if (it.find("#") == 0)
                continue;
            if (mode == CHIPSET) {
                // if (!ParseChipset(stock, it))
                //     std::cerr << "Invalid chipset" << std::endl;
            }
            else { // mode == LINK
                if (!ParseLink(stock, it))
                    std::cerr << "Invalid link" << std::endl;
            }
        }
        return true;
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
        ParseFile(stock);
    }
}
