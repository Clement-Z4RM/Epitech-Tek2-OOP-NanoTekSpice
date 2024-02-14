/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Xor.cpp
*/

#include "Xor.hpp"

nts::Tristate nts::Xor::compute(std::size_t pin) {
    Tristate state1 = at(1);
    Tristate state2 = at(2);

    switch (pin) {
        case 1:
            return state1;
        case 2:
            return state2;
        case 3:
            return (state1 != state2) ? True : False;
        default:
            return Undefined;
    }
}
