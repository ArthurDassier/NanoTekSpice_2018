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
    nts::Tristate val3;

    if (_list[in1].cmp == NULL || _list[in2].cmp == NULL || _list[in3].cmp == NULL)
        return (nts::UNDEFINED);
    nts::Tristate val1 = _list[in1].cmp->compute(_list[in1].output);
    nts::Tristate val2 = _list[in2].cmp->compute(_list[in2].output);
    if (in3 == 9)
        val3 = _list[in3].cmp->compute(_list[in3].output);
    else
        val3 = _C;
    if ((val1 == nts::TRUE && val2 == nts::TRUE)
    || (((val1 == nts::TRUE) ^ (val2 == nts::TRUE)) && val3 == nts::TRUE))
        _C = nts::TRUE;
    else
        _C = nts::FALSE;
    if (((val1 == nts::TRUE) ^ (val2 == nts::TRUE)) ^ (val3 == nts::TRUE))
        return (nts::TRUE);
    return (nts::FALSE);
}

nts::Tristate Component_4008::compute(std::size_t pin)
{
    if (!(check_output(pin)))
        return (nts::UNDEFINED);
    if (pin == 10) {
        return (operand(6, 7, 9));
    }
    if (pin == 11) {
        compute(10);
        return (operand(4, 5, 10));
    }
    if (pin == 12) {
        compute(11);
        return (operand(2, 3, 11));
    }
    if (pin == 13) {
        compute(12);
        return (operand(1, 15, 12));
    }
    if (pin == 14) {
        compute(13);
        return (_C);
    }
    return (nts::UNDEFINED);
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

