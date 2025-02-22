/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4069.cpp
*/

#include "Component4069.hpp"

nts::Component4069::Component4069() : AComponent(_4069, 14) {
    _excludedPins.push_back(7);
    _excludedPins.push_back(14);
}

nts::Tristate nts::Component4069::compute(std::size_t pin) {
    if (pin == 2 || pin == 4 || pin == 6)
        return !getLink(pin - 1);
    if (pin == 8 || pin == 10 || pin == 12)
        return !getLink(pin + 1);
    return Undefined;
}
