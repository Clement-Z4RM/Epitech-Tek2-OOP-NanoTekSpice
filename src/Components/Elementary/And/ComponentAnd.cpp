/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentAnd.cpp
*/

#include "ComponentAnd.hpp"

nts::ComponentAnd::ComponentAnd() : AComponent(_and, 3) {}

nts::Tristate nts::ComponentAnd::compute(std::size_t pin) {
    Tristate state1 = getLink(1);
    Tristate state2 = getLink(2);

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
