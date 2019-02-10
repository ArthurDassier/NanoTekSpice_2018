#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <unordered_map>
#include <memory>
#include "IComponent.hpp"
#include "Component_4001.hpp"
#include "Component_4008.hpp"
#include "Component_4013.hpp"
#include "Component_4011.hpp"
#include "Component_4017.hpp"
#include "Component_4030.hpp"
#include "Component_4040.hpp"
#include "Component_4069.hpp"
#include "Component_4071.hpp"
#include "Component_4081.hpp"
#include "Component_4094.hpp"
#include "Component_4514.hpp"
#include "Component_4801.hpp"
#include "Component_4094.hpp"
#include "Component_4514.hpp"
#include "Component_4801.hpp"
#include "Component_2716.hpp"

#include "Clock.hpp"
#include "False.hpp"
#include "True.hpp"
#include "Output.hpp"
#include "Input.hpp"

class Factory
{
public:

    Factory()
    {}

    nts::IComponent *createComponent(const std::string &type, const std::string &value)
    {
        const std::string keys[20] = {"4001", "4008", "4013", "4011", "4017", "4030"
                                , "4040", "4069", "4071", "4081", "4094", "4514"
                                , "4801", "2716", "input", "clock", "false", "true", "output"};
        int i = 0;

        for (; i != 20; i++) {
            if (keys[i] == type)
                break;
        }
        switch (i) {
            case 0:
                return create4001(value);
            break;
            case 1:
                return create4008(value);
                break;
            case 2:
                return create4013(value);
                break;
            case 3:
                return create4011(value);
                break;
            case 4:
                return create4017(value);
                break;
            case 5:
                return create4030(value);
                break;
            case 6:
                return create4040(value);
                break;
            case 7:
                return create4069(value);
                break;
            case 8:
                return create4071(value);
                break;
            case 9:
                return create4081(value);
                break;
            case 10:
                return create4094(value);
                break;
            case 11:
                return create4514(value);
                break;
            case 12:
                return create4801(value);
                break;
            case 13:
                return create2716(value);
                break;
            case 14:
                return createInput(value);
                break;
            case 15:
                return createClock(value);
                break;
            case 16:
                return createFalse(value);
                break;
            case 17:
                return createTrue(value);
                break;
            case 18:
                return createOutput(value);
                break;
            case 19:
                ;
                break;
        }
        return nullptr;
    }

    nts::IComponent *create4001(const std::string &value)
    {
        static std::vector<std::shared_ptr<Component_4001>> sp;

        sp.push_back(std::make_shared<Component_4001>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4008(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4008>> sp;

        sp.push_back(std::make_shared<Component_4008>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4013(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4013>> sp;

        sp.push_back(std::make_shared<Component_4013>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4011(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4011>> sp;

        sp.push_back(std::make_shared<Component_4011>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4017(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4017>> sp;

        sp.push_back(std::make_shared<Component_4017>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4030(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4030>> sp;

        sp.push_back(std::make_shared<Component_4030>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4040(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4040>> sp;

        sp.push_back(std::make_shared<Component_4040>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4069(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4069>> sp;

        sp.push_back(std::make_shared<Component_4069>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4071(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4071>> sp;

        sp.push_back(std::make_shared<Component_4071>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4081(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4081>> sp;

        sp.push_back(std::make_shared<Component_4081>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4094(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4094>> sp;

        sp.push_back(std::make_shared<Component_4094>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4514(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4514>> sp;

        sp.push_back(std::make_shared<Component_4514>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create4801(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_4801>> sp;

        sp.push_back(std::make_shared<Component_4801>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *create2716(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Component_2716>> sp;

        sp.push_back(std::make_shared<Component_2716>(value));
        std::cout << sp.end()->get()->getName() << std::endl;
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *createTrue(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<True>> sp;

        sp.push_back(std::make_shared<True>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *createFalse(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<False>> sp;

        sp.push_back(std::make_shared<False>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *createInput(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Input>> sp;

        sp.push_back(std::make_shared<Input>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *createOutput(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Output>> sp;

        sp.push_back(std::make_shared<Output>(value));
        return sp[sp.size() - 1].get();
    }

    nts::IComponent *createClock(const std::string &value) const noexcept
    {
        static std::vector<std::shared_ptr<Clock>> sp;

        sp.push_back(std::make_shared<Clock>(value));
        return sp[sp.size() - 1].get();
    }

private:
};

#endif
