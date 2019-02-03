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
        if (!chipset)
            throw "Miss Chipset part";
        if (!link)
            throw "Miss Link part";
        return true;
    }

    bool Parser::ParseChipset(std::vector<std::string> &stock, std::string &it)
    {
        std::string SpeComp[5] = {"input", "clock", "false", "true", "output"};
        std::string comps[] = {"4001", "4008", "4013", "4011", "4017", "4030"
                                , "4040", "4069", "4071", "4081", "4094", "4514"
                                , "4801", "2716", "4004"};
        bool check_comp = false;
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
                return true;
            }
        }
        if (std::isdigit(it[0])) {
            if ((ret = it.find_first_of(' ')) != std::string::npos)
                tmp = it.substr(0, ret);
            if ((ret = it.find_first_of('\t')) != std::string::npos)
                tmp = it.substr(0, ret);
            type = tmp;
            for (auto &it_com : comps) {
                if (it_com == type)
                    check_comp = true;
            }
            if (!check_comp)
                throw std::invalid_argument("This component: '" + type + "' doesn't exist");
            std::cout << "compenant find ! " << type << std::endl;
            tmp = it.substr(type.size());
            if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
                tmp = tmp.substr(ret);
            if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
                tmp = tmp.substr(ret);
            std::cout << "its name is ! " << tmp << std::endl;
            // check if already exist a comp with the same name
            // factory(type, tmp);
            // !\\ ajouter au circus vector
            return true;
        }
        if (it != "")
            throw std::invalid_argument("Invalid syntax ! : '" + it + "'");
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
            if ((ret2 = it.find_first_of(" ")) != std::string::npos)
                pin_male = it.substr(ret + 1, ret2 - (ret + 1));
            if ((ret2 = it.find_first_of("\t")) != std::string::npos)
                pin_male = it.substr(ret + 1, ret2 - (ret + 1));
        }
        if ((ret = it.rfind(":")) != std::string::npos) {
            ret2 = it.rfind(" ");
            ret2 = it.rfind("\t");
            fem = it.substr(ret2 + 1, ret - (ret2 + 1));
            pin_fem = it.substr(ret + 1);
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
                try {
                    if (!ParseChipset(stock, it))
                        std::cerr << "Invalid chipset" << std::endl;
                } catch(const std::invalid_argument &error_chipset) {
                    std::cerr << error_chipset.what() << std::endl;
                    exit(-1);
                }
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
        try {
            if (!file.is_open())
                throw "Open fail, the file doesn't existe ?";
            while (!file.eof()) {
                getline(file, tmp);
                stock.push_back(tmp);
            }
        } catch(const std::string &open) {
            std::cerr << "Exception: " << open << std::endl;
            exit(-1);
        }
        try {
            CheckMainError(stock);
        } catch(const char* &main_error) {
            std::cerr << "Exception: " << main_error << std::endl;
            exit(-1);
        }
        ParseFile(stock);
    }
}
