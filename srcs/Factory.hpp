#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <memory>
#include "IComponent.hpp"

class Factory;

typedef std::unique_ptr<IComponent> (*Factory::ptr)(const std:: string &value)

class Factory
{
public:
    Factory()
    {
        ref["4001"] = &create4001;
        ref["4008"] = &create4008;
        ref["4013"] = &create4013;
        ref["4011"] = &create4011;
        ref["4017"] = &create4017;
        ref["4030"] = &create4030;
        ref["4040"] = &create4040;
        ref["4069"] = &create4069;
        ref["4071"] = &create4071;
        ref["4081"] = &create4081;
        ref["4094"] = &create4094;
        ref["4514"] = &create4514;
        ref["4801"] = &create4801;
        ref["2716"] = &create2716;
        ref["input"] = &create4081;
        ref["true"] = &create4094;
        ref["false"] = &create4514;
        ref["output"] = &create4801;
        ref["clock"] = &create2716;
    }

    std::unique_ptr<IComponent> createComponent(const std::string &type, const std::string &value)
    {
        return (ref[type](value));
    }

    std::unique_ptr<IComponent> create4001(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4001> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create4008(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4008> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create4013(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4013> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create4017(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4017> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create4030(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4030> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create4040(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4040> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create4069(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4069> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create4071(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4071> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create4081(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4081> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create4094(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4094> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create4514(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4514> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create4801(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_4801> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> create2716(const std::string &value) const noexcept
    {
        std::unique_ptr<Component_2716> comp(value);
        return comp;
    }

    std::unique_ptr<IComponent> createTrue(const std::string &value) const noexcept
    {
        std::unique_ptr<True> speComp(value);
        return speComp;
    }

    std::unique_ptr<IComponent> createFalse(const std::string &value) const noexcept
    {
        std::unique_ptr<False> speComp(value);
        return speComp;
    }

    std::unique_ptr<IComponent> createInput(const std::string &value) const noexcept
    {
        std::unique_ptr<Input> speComp(value);
        return speComp;
    }

    std::unique_ptr<IComponent> createOutput(const std::string &value) const noexcept
    {
        std::unique_ptr<Output> speComp(value);
        return speComp;
    }

    std::unique_ptr<IComponent> createClock(const std::string &value) const noexcept
    {
        std::unique_ptr<Clock> speComp(value);
        return speComp;
    }
private:
    std::unordered_map<ptr> ref;
};

#endif
