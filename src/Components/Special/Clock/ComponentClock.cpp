/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentClock.cpp
*/

#include "ComponentClock.hpp"

nts::Tristate nts::ComponentClock::compute(std::size_t pin) {
    if (pin == 1)
        return _state ? True : False;
    return Undefined;
}

void nts::ComponentClock::updateState(bool state) {
    _state = state;
}
