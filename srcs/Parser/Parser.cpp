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
        size_t pos = 0;
        std::string tmp;
        size_t ret;

        for (auto &it : stock) {
            if ((pos = std::string(it.data()).find("#")) == 0)
                continue;
            if ((pos = std::string(it.data()).find("input")) != std::string::npos) {
                tmp = std::string(it.data()).substr(5);
                if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
                    tmp = tmp.substr(ret);
                if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
                    tmp = tmp.substr(ret);
                // std::unique_ptr<Input> new_input(tmp);
                // !\\ ajouter au circus vector
                std::cout << "Input find ! " << tmp << std::endl;
            }
            if ((pos = std::string(it.data()).find("clock")) != std::string::npos) {
                tmp = std::string(it.data()).substr(5);
                if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
                    tmp = tmp.substr(ret);
                if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
                    tmp = tmp.substr(ret);
                // std::unique_ptr<Input> new_input(tmp);
                // !\\ ajouter au circus vector
                std::cout << "Clock find ! " << tmp << std::endl;
            }
            if ((pos = std::string(it.data()).find("false")) != std::string::npos) {
                tmp = std::string(it.data()).substr(5);
                if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
                    tmp = tmp.substr(ret);
                if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
                    tmp = tmp.substr(ret);
                // std::unique_ptr<Input> new_input(tmp);
                // !\\ ajouter au circus vector
                std::cout << "False find ! " << tmp << std::endl;
            }
            if ((pos = std::string(it.data()).find("true")) != std::string::npos) {
                tmp = std::string(it.data()).substr(5);
                if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
                    tmp = tmp.substr(ret);
                if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
                    tmp = tmp.substr(ret);
                // std::unique_ptr<Input> new_input(tmp);
                // !\\ ajouter au circus vector
                std::cout << "True find ! " << tmp << std::endl;
            }
            if ((pos = std::string(it.data()).find("output")) != std::string::npos) {
                tmp = std::string(it.data()).substr(6);
                if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
                    tmp = tmp.substr(ret);
                if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
                    tmp = tmp.substr(ret);
                // std::unique_ptr<Input> new_input(tmp);
                // !\\ ajouter au circus vector
                std::cout << "output find ! " << tmp << std::endl;
            }
            else {
                if ((ret = tmp.find_first_of('4')) != std::string::npos);
                    std::cout << "compenant find ! " << tmp << std::endl;
                //     tmp = tmp.substr(0, ret);
                // if ((ret = tmp.find_first_of('\t')) != std::string::npos);
                //     tmp = tmp.substr(0, ret);
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
        if (!ParseChipset(stock))
            std::cerr << "Invalid chipset" << std::endl;
    }
}
