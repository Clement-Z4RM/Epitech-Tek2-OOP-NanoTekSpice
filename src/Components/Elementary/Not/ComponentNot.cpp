/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentNot.cpp
*/

#include "ComponentNot.hpp"

nts::ComponentNot::ComponentNot() : AComponent(_not, 2) {}

nts::Tristate nts::ComponentNot::compute(std::size_t pin) {
    Tristate state = at(1);

    switch (pin) {
        case 1:
            return state;
        case 2:
            return !state;
        default:
            return Undefined;
    }
}
