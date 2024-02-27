/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentOutput.cpp
*/

#include "ComponentOutput.hpp"

nts::ComponentOutput::ComponentOutput() : AComponent(_output, 1) {}

void nts::ComponentOutput::simulate(std::size_t tick) {
    if (tick != _tick) {
        Link &link = _links.at(1);

        _state = link.other.compute(link.otherPin);
        _tick = tick;
    }
}

nts::Tristate nts::ComponentOutput::compute(std::size_t pin) {
    if (pin == 1)
        return _state;
    return Undefined;
}
