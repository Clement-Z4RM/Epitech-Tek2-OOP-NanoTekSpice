/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4001.cpp
*/

#include "Component4001.hpp"

nts::Component4001::Component4001() : AComponent(_4001, 14) {
    _excludedPins.push_back(7);
    _excludedPins.push_back(14);
}

nts::Tristate nts::Component4001::compute(std::size_t pin) {
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        size_t input1Pin, input2Pin;
        if (pin == 3 || pin == 4) {
            input1Pin = pin - 1;
            input2Pin = pin - 2;
        } else {
            input1Pin = pin - 5;
            input2Pin = pin - 6;
        }
        Tristate input1 = getLink(input1Pin);
        Tristate input2 = getLink(input2Pin);
        return !(input1 || input2);
    }
    return Undefined;
}
