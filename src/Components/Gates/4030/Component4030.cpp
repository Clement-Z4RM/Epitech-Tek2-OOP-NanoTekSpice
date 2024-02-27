/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4030.cpp
*/

#include "Component4030.hpp"

nts::Component4030::Component4030() : AComponent(_4030, 14) {
    _excludedPins.push_back(7);
    _excludedPins.push_back(14);
}

nts::Tristate nts::Component4030::compute(std::size_t pin) {
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        std::size_t in1;
        std::size_t in2;

        if (pin == 3 || pin == 10) {
            in1 = pin - 1;
            in2 = pin - 2;
        } else {
            in1 = pin + 1;
            in2 = pin + 2;
        }
        return (getLink(in1) ^ getLink(in2));
    }
    return Undefined;
}
