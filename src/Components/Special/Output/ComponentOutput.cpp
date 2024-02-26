/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentOutput.cpp
*/

#include "ComponentOutput.hpp"

nts::Tristate nts::ComponentOutput::compute(std::size_t pin) {
    if (pin == 1 && _returnValue != Undefined)
        return _returnValue;
    return Undefined;
}

void nts::ComponentOutput::setValue(nts::Tristate value) {
    _returnValue = value;
}
