/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Output.cpp
*/

#include "Output.hpp"

nts::Tristate nts::Output::compute(std::size_t pin) {
    if (pin == 1 && _returnValue != Undefined)
        return _returnValue;
    return Undefined;
}

void nts::Output::setValue(nts::Tristate value) {
    _returnValue = value;
}
