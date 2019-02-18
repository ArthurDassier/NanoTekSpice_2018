#include "Parser.hpp"

namespace parser
{
    Parser::Parser(std::string name, Circus &my_circus, Factory &my_factory) : _circus(my_circus), factory(my_factory), filename(name)
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
        if (!chipset) {
            throw ErrorNano("Miss Chipset part");
            return false;
        }
        if (!link) {
            throw ErrorNano("Miss Link part");
            return false;
        }
        return true;
    }

    bool Parser::ParseChipset(std::string &it)
    {
        const std::string SpeComp[5] = {"input", "clock", "false", "true", "output"};
        const std::string comps[] = {"4001", "4008", "4013", "4011", "4017", "4030"
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
                _circus.addComponent(*(factory.createComponent(it2, tmp)));
                try {
                    if (!(tmp.find(' ') == std::string::npos
                        && tmp.find('\t') == std::string::npos))
                        throw ErrorNano("this special component doesn't have name !!");
                }
                catch (const ErrorNano &main_error) {
                    std::cerr << "Exception: " << main_error.what() << std::endl;
                    exit(-1);
                }
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
            tmp = it.substr(type.size());
            if ((ret = tmp.find_first_not_of(' ')) != std::string::npos)
                tmp = tmp.substr(ret);
            if ((ret = tmp.find_first_not_of('\t')) != std::string::npos)
                tmp = tmp.substr(ret);
            try {
                if (!(tmp.find(' ') == std::string::npos
                    && tmp.find('\t') == std::string::npos))
                    throw ErrorNano("this component doesn't have name !!");
            }
            catch (const ErrorNano &main_error) {
                std::cerr << "Exception: " << main_error.what() << std::endl;
                exit(-1);
            }
            std::vector<nts::IComponent *> tmp_circus = _circus.getCircus();

            for (auto &it : tmp_circus) {
                try {
                    if (it->getName() == tmp)
                        throw ErrorNano("this component already exist");
                }
                catch (const ErrorNano &main_error) {
                    std::cerr << "Exception: " << main_error.what() << std::endl;
                    exit(-1);
                }
            }
            _circus.addComponent(*(factory.createComponent(type, tmp)));
            return true;
        }
        if (it != "")
            throw ErrorNano("Invalid syntax ! : '" + it + "'");
        return true;
    }

    bool Parser::ParseLink(std::string &it)
    {
        size_t ret;
        size_t ret2;
        std::string male;
        std::string pin_male;
        std::string fem;
        std::string pin_fem;

        if (it.size() == 0)
            return true;
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
        std::vector<nts::IComponent *> tmp_circus = _circus.getCircus();
        for (auto &it : tmp_circus) {
            if (it->getName() == male) {
                for (auto &it2 : tmp_circus) {
                    if (it2->getName() == fem) {
                        if (it2->check_input(std::stoi(pin_fem))) {
                            if (!(it->check_output(std::stoi(pin_male))))
                                return (false);
                            it2->setLink(static_cast<size_t>(std::stoi(pin_fem)), *it, static_cast<size_t>(std::stoi(pin_male)));
                            return (true);
                        } else {
                            if (!(it2->check_output(std::stoi(pin_fem))))
                                return (false);
                            it->setLink(static_cast<size_t>(std::stoi(pin_male)), *it2, static_cast<size_t>(std::stoi(pin_fem)));
                            return (true);
                        }
                    }
                }
            }
        }
        return (false);
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
                    if (!ParseChipset(it))
                        throw ErrorNano("Invalid chipset");
                } catch (const ErrorNano &error_chipset) {
                    std::cerr << error_chipset.what() << std::endl;
                    exit(-1);
                }
            }
            else {
                try {
                    if (!ParseLink(it))
                        throw ErrorNano("Invalid link");
                }
                catch (const ErrorNano &error_chipset) {
                    std::cerr << error_chipset.what() << std::endl;
                    exit(-1);
                }
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
                throw ErrorNano("Open fail, the file doesn't existe ?");
            while (!file.eof()) {
                getline(file, tmp);
                stock.push_back(tmp);
            }
        } catch(const ErrorNano &open) {
            std::cerr << "Exception: " << open.what() << std::endl;
            exit(-1);
        }
        try {
            CheckMainError(stock);
        } catch(const ErrorNano &main_error) {
            std::cerr << "Exception: " << main_error.what() << std::endl;
            exit(-1);
        }
        ParseFile(stock);
    }
}
