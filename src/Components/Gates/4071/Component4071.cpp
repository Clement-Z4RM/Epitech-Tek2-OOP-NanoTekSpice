/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4071.cpp
*/

#include "Component4071.hpp"

nts::Tristate nts::Component4071::compute(std::size_t pin) {
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
        return (input1 || input2);
    } else
        return Undefined;
}
