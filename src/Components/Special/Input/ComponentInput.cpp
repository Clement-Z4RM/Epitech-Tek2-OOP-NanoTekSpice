/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentInput.cpp
*/

#include "ComponentInput.hpp"

nts::ComponentInput::ComponentInput() : AComponent(_input, 1) {}

void nts::ComponentInput::simulate([[maybe_unused]] std::size_t tick) {
    if (_hasChanged) {
        _state = _nextState;
        _hasChanged = false;
    }
}

nts::Tristate nts::ComponentInput::compute(std::size_t pin) {
    if (pin == 1)
        return _state;
    return Undefined;
}
