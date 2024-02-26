/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentClock.cpp
*/

#include "ComponentClock.hpp"

nts::ComponentClock::ComponentClock() : AComponent(_clock, 1) {}

nts::Tristate nts::ComponentClock::compute(std::size_t pin) {
    if (pin == 1)
        return _state;
    return Undefined;
}
