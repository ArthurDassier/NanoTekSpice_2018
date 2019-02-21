#include "Parser.hpp"

namespace parser
{
    Parser::Parser(std::string name, Circus &my_circus, Factory &my_factory)
    : _circus(my_circus), factory(my_factory), filename(name)
    {}

    Parser::~Parser()
    {}

    bool Parser::CheckMainError(std::vector<std::string> &stock)
    {
        bool link = false, chipset = false;

        for (auto &it : (stock)) {
            if (it == std::string(".links:"))
                link = true;
            else if (it == std::string(".chipsets:"))
                chipset = true;
        }
        if (!chipset) {
            throw ErrorNano("Miss Chipset part");
            return (false);
        }
        if (!link) {
            throw ErrorNano("Miss Link part");
            return (false);
        }
        return (true);
    }

    bool Parser::ParseChipsetFindSpeComp(std::string &it)
    {
        const std::string SpeComp[5] = {"input", "clock", "false", "true", "output"};
        std::string tmp;
        size_t ret;

        for (auto &it2 : SpeComp) {
            if (it.find(it2) != std::string::npos) {
                tmp = it.substr(it2.size());
                if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
                    tmp = tmp.substr(ret);
                if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
                    tmp = tmp.substr(ret);
                _circus.addComponent(*(factory.createComponent(it2, tmp)));
                if (!(tmp.find(' ') == std::string::npos
                    && tmp.find('\t') == std::string::npos))
                    throw ErrorNano("this special component doesn't have name !!");
                return (true);
            }
        }
        return (false);
    }

    void Parser::FindTypeComponentToCreat(std::string &it, std::string &tmp,
                                        std::string &type)
    {
        const std::string comps[] = {"4001", "4008", "4013", "4011", "4017",
                                "4030", "4040", "4069", "4071", "4081", "4094",
                                "4514", "4801", "2716", "4004"};
        size_t ret;
        bool check_comp = false;

        if ((ret = it.find_first_of(' ')) != std::string::npos)
            tmp = it.substr(0, ret);
        if ((ret = it.find_first_of('\t')) != std::string::npos)
            tmp = it.substr(0, ret);
        type = tmp;
        for (auto &it_com : comps)
            if (it_com == type)
                check_comp = true;
        if (!check_comp)
            throw std::invalid_argument("This component: '"
                                        + type + "' doesn't exist");
    }

    void Parser::FindNameComponentToCreat(std::string &it, std::string &tmp,
                                        std::string &type)
    {
        size_t ret;

        tmp = it.substr(type.size());
        if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
            tmp = tmp.substr(ret);
        if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
            tmp = tmp.substr(ret);
        if (!(tmp.find(' ') == std::string::npos
            && tmp.find('\t') == std::string::npos))
            throw ErrorNano("this component doesn't have name !!");
    }

    void Parser::FindComponentToCreat(std::string &it, std::string &tmp,
                                        std::string &type)
    {
        FindTypeComponentToCreat(it, tmp, type);
        FindNameComponentToCreat(it, tmp, type);
    }

    bool Parser::ParseChipsetFindComp(std::string &it)
    {
        std::string tmp;
        std::string type;

        if (std::isdigit(it[0])) {
            FindComponentToCreat(it, tmp, type);
            std::vector<nts::IComponent *> tmp_circus = _circus.getCircus();

            for (auto &it : tmp_circus)
                if (it->getName() == tmp)
                    throw ErrorNano("this component already exist");
            _circus.addComponent(*(factory.createComponent(type, tmp)));
            return (true);
        }
        return (false);
    }

    bool Parser::ParseChipset(std::string &it)
    {
        if (ParseChipsetFindSpeComp(it))
            return (true);
        if (ParseChipsetFindComp(it))
            return (true);
        if (it != "")
            throw ErrorNano("Invalid syntax ! : '" + it + "'");
        return (true);
    }

    bool Parser::BuildLink(std::string pin_male, std::string pin_fem,
                        nts::IComponent *it, nts::IComponent *it2)
    {
        if (it2->check_input(std::stoi(pin_fem))) {
            if (!(it->check_output(std::stoi(pin_male))))
                return (false);
            it2->setLink(static_cast<size_t>(std::stoi(pin_fem)),
                        *it, static_cast<size_t>(std::stoi(pin_male)));
            return (true);
        } else {
            if (!(it2->check_output(std::stoi(pin_fem))))
                return (false);
            it->setLink(static_cast<size_t>(std::stoi(pin_male)),
                        *it2, static_cast<size_t>(std::stoi(pin_fem)));
            return (true);
        }
    }

    void Parser::FindPinComponentToLink(std::string &it,
                std::string &male, std::string &pin_male,
                std::string &fem, std::string &pin_fem)
    {
        size_t ret;
        size_t ret2;

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
    }

    bool Parser::ParseLink(std::string &it)
    {
        std::string male;
        std::string pin_male;
        std::string fem;
        std::string pin_fem;

        if (it.size() == 0)
            return (true);
        FindPinComponentToLink(it, male, pin_male, fem, pin_fem);
        std::vector<nts::IComponent *> tmp_circus = _circus.getCircus();
        for (auto &it : tmp_circus)
            if (it->getName() == male)
                for (auto &it2 : tmp_circus)
                    if (it2->getName() == fem)
                        return (BuildLink(pin_male, pin_fem, it, it2));
        return (false);
    }

    void Parser::FinalCheck()
    {
        std::vector<nts::IComponent *> tmp_circus = _circus.getCircus();

        for (auto &it : tmp_circus) {
            if (it->getType() == "output")
                if (!static_cast<Output*>(it)->getComponent())
                    throw ErrorNano("output not linked");
        }
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
                if (!ParseChipset(it))
                    throw ErrorNano("Invalid chipset");
            } else
                if (!ParseLink(it))
                    throw ErrorNano("Invalid link");
        }
        FinalCheck();
        return (true);
    }

    void Parser::SaveFile(std::vector<std::string> &stock)
    {
        std::string tmp;
        std::ifstream file;

        file.open(filename);
        try {
            if (!file.is_open())
                throw ErrorNano("Open fail, the file doesn't exist ?");
            while (!file.eof()) {
                getline(file, tmp);
                stock.push_back(tmp);
            }
        } catch(const ErrorNano &open) {
            std::cerr << "Exception: " << open.what() << std::endl;
            exit(84);
        }
    }

    void Parser::LetsParse()
    {
        std::vector<std::string> stock;

        SaveFile(stock);
        try {
            CheckMainError(stock);
        } catch(const ErrorNano &main_error) {
            std::cerr << "Exception: " << main_error.what() << std::endl;
            exit(84);
        }
        try {
            ParseFile(stock);
        } catch (const ErrorNano &error_parsing) {
            std::cerr << error_parsing.what() << std::endl;
            exit(84);
        }
    }
}
