/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Clock.cpp
*/

#include "Clock.hpp"

nts::Tristate nts::Clock::compute(std::size_t pin) {
    if (pin == 1)
        return _state ? True : False;
    return Undefined;
}

void nts::Clock::updateState(bool state) {
    _state = state;
}
