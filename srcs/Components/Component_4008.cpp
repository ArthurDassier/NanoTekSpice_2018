/*
** EPITECH PROJECT, 2019
** Component_4008.cpp
** File description:
** 4008
*/

#include "Component_4008.hpp"

Component_4008::Component_4008(std::string name)
{
    _name = name;
    _type = "4008";
    _C = nts::UNDEFINED;
    nts::link_t setter;

    setter.cmp = NULL;
    setter.output = 0;
    for(size_t i = 0; i != 15; ++i)
        _list.push_back(setter);
    _list[10].cmp = this;
    _list[11].cmp = this;
    _list[12].cmp = this;
}

Component_4008::~Component_4008()
{
}

nts::Tristate Component_4008::operand(std::size_t in1, std::size_t in2, std::size_t in3)
{
    if (_list[in1].cmp == NULL || _list[in2].cmp == NULL || _list[in3].cmp == NULL)
        return (nts::UNDEFINED);
    _C = nts::FALSE;
    nts::Tristate val1 = _list[in1].cmp->compute(_list[in1].output);
    nts::Tristate val2 = _list[in2].cmp->compute(_list[in2].output);
    nts::Tristate val3 = _list[in3].cmp->compute(_list[in3].output);
    if (!(val1 == nts::TRUE ^ val2 == nts::TRUE)) {
        if (val1 == nts::TRUE && val2 == nts::TRUE)
            _C = nts::TRUE;
        if (val3 == nts::FALSE)
            return (nts::FALSE);
        else
            return (nts::TRUE);
    }
    if (val3 == nts::TRUE)
        _C = nts::TRUE;
    if (val3 == nts::TRUE)
        return (nts::FALSE);
    else
        return (nts::TRUE);
}

nts::Tristate Component_4008::compute(std::size_t pin)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin == 10) {
        std::cout << "1 : " << _C << std::endl;
        return (operand(6, 7, 9));
    }
    if (pin == 11) {
        std::cout << "2 : " << _C << std::endl;
        return (operand(4, 5, 10));
    }
    if (pin == 12) {
        std::cout << "3 : " << _C << std::endl;
        return (operand(2, 3, 11));
    }
    if (pin == 13) {
        std::cout << "4 : " << _C << std::endl;
        return (operand(1, 15, 12));
    }
    if (pin == 14) {
        compute(13);
        return (_C);
    }
    return (nts::UNDEFINED);
}

void Component_4008::dump() const
{
    std::cout << _name << std::endl;
}

bool Component_4008::check_input(std::size_t pin)
{
    if ((pin >= 1 && pin <= 7) || pin == 9 || pin == 15)
        return (true);
    return (false);
}

bool Component_4008::check_output(std::size_t pin)
{
    if (pin == 10 || pin == 11 || pin == 12 || pin == 13 || pin == 14)
        return (true);
    return (false);
}

