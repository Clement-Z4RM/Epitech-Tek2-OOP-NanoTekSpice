/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentClock.cpp
*/

#include "ComponentClock.hpp"

nts::ComponentClock::ComponentClock() : AComponent(_clock, 1) {}

void nts::ComponentClock::simulate(std::size_t tick) {
    if (tick != _tick) {
        if (_hasChanged) {
            _state = _nextState;
            _hasChanged = false;
        } else if (_state != Undefined)
            _state = !_state;
        _tick = tick;
    }
}

nts::Tristate nts::ComponentClock::compute(std::size_t pin) {
    if (pin == 1)
        return _state;
    return Undefined;
}
