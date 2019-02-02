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
        std::string SpeComp[5] = {"input", "clock", "false", "true", "ouput"};
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
                std::cout << "Input find ! " << tmp << std::endl;
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
        }
        return true;
    }

    bool Parser::ParseLink(std::vector<std::string> &stock, std::string &it)
    {
        // std::string SpeComp[5] = {"input", "clock", "false", "true", "ouput"};
        // std::string tmp;
        // size_t ret;
        //
        // for (auto &it2 : SpeComp) {
        //     if (it.find(it2) != std::string::npos) {
        //         tmp = it.substr(it2.size());
        //         if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
        //             tmp = tmp.substr(ret);
        //         if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
        //             tmp = tmp.substr(ret);
        //         // std::unique_ptr<Input> new_input(tmp);
        //         // !\\ ajouter au circus vector
        //         std::cout << "Input find ! " << tmp << std::endl;
        //         break;
        //     }
        // }
        // if (std::isdigit(std::string(it.data())[0])) {
        //     if ((ret = it.find_first_of(' ')) != std::string::npos)
        //         tmp = it.substr(0, ret);
        //     if ((ret = it.find_first_of('\t')) != std::string::npos)
        //         tmp = it.substr(0, ret);
        //     std::cout << "compenant find ! " << tmp << std::endl;
        // }
        return true;
    }

    bool Parser::ParseMode(std::vector<std::string> &stock)
    {
        mode_e mode = UNKNOW;

        for (auto &it : stock) {
            if (it == std::string(".links:"))
                mode = LINK;
            if (it == std::string(".chipsets:"))
                mode = CHIPSET;
            if (std::string(it.data()).find("#") == 0)
                continue;
            if (mode == CHIPSET) {
                if (!ParseChipset(stock, it))
                    std::cerr << "Invalid chipset" << std::endl;
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
        ParseMode(stock);
    }
}
