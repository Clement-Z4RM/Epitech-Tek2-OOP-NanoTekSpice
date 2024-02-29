/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4008.cpp
*/

#include "Component4008.hpp"

nts::Component4008::Component4008() : AComponent(_4008, 16){
    _excludedPins.push_back(8);
    _excludedPins.push_back(16);
}

nts::Tristate nts::Component4008::compute(std::size_t pin) {
    if (pin == 14)
        return _carry;
    if (pin < 10 || pin > 14)
        return getLink(pin);

    Tristate inputs[16] = {
            Undefined,
            getLink(1),
            getLink(2),
            getLink(3),
            getLink(4),
            getLink(5),
            getLink(6),
            getLink(7),
            Undefined,
            getLink(9),
            Undefined,
            Undefined,
            Undefined,
            Undefined,
            Undefined,
            getLink(15)
    };

    if (inputs[6] == Undefined || inputs[7] == Undefined || inputs[9] == Undefined)
        return Undefined;
    inputs[10] = (inputs[6] ^ inputs[7]) ^ inputs[9];
    if (pin == 10) {
        _carry = (inputs[6] && inputs[7]) || (inputs[6] && inputs[9]) || (inputs[7] && inputs[9]);
        return inputs[10];
    }

    if (inputs[4] == Undefined || inputs[5] == Undefined)
        return Undefined;
    inputs[11] = (inputs[4] ^ inputs[5]) ^ inputs[10];
    if (pin == 11) {
        _carry = (inputs[4] && inputs[5]) || (inputs[4] && inputs[10]) || (inputs[5] && inputs[10]);
        return inputs[11];
    }

    if (inputs[2] == Undefined || inputs[3] == Undefined)
        return Undefined;
    inputs[12] = (inputs[2] ^ inputs[3]) ^ inputs[11];
    if (pin == 12) {
        _carry = (inputs[2] && inputs[3]) || (inputs[2] && inputs[11]) || (inputs[3] && inputs[11]);
        return inputs[12];
    }

    if (inputs[1] == Undefined || inputs[15] == Undefined)
        return Undefined;
    inputs[13] = (inputs[1] ^ inputs[15]) ^ inputs[12];
    _carry = (inputs[1] && inputs[15]) || (inputs[1] && inputs[12]) || (inputs[15] && inputs[12]);
    return inputs[13];
}
