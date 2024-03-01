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
    if (pin < 10 || pin > 14)
        return getLink(pin);

    Tristate pins[16] = {
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
    Tristate carry = Undefined;

    if (pins[6] == Undefined || pins[7] == Undefined || pins[9] == Undefined)
        return Undefined;
    pins[10] = (pins[6] ^ pins[7]) ^ pins[9];
    if (pin == 10)
        return pins[10];
    carry = (pins[6] && pins[7]) || (pins[6] && pins[9]) || (pins[7] && pins[9]);

    if (pins[4] == Undefined || pins[5] == Undefined)
        return pin == 14 ? carry : Undefined;
    pins[11] = (pins[4] ^ pins[5]) ^ carry;
    if (pin == 11)
        return pins[11];
    carry = (pins[4] && pins[5]) || (pins[4] && carry) || (pins[5] && carry);

    if (pins[2] == Undefined || pins[3] == Undefined)
        return pin == 14 ? carry : Undefined;
    pins[12] = (pins[2] ^ pins[3]) ^ carry;
    if (pin == 12)
        return pins[12];
    carry = (pins[2] && pins[3]) || (pins[2] && carry) || (pins[3] && carry);

    if (pins[1] == Undefined || pins[15] == Undefined)
        return pin == 14 ? carry : Undefined;
    pins[13] = (pins[1] ^ pins[15]) ^ carry;
    if (pin == 13)
        return pins[13];
    return (pins[1] && pins[15]) || (pins[1] && carry) || (pins[15] && carry);
}
