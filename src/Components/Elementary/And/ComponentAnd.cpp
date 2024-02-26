/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentAnd.cpp
*/

#include "ComponentAnd.hpp"
#include <iostream>

nts::Tristate nts::ComponentAnd::compute(std::size_t pin) {
    Tristate state1 = at(1);
    Tristate state2 = at(2);

    switch (pin) {
        case 1:
            return state1;
        case 2:
            return state2;
        case 3:
            return state1 && state2;
        default:
            return Undefined;
    }
}
