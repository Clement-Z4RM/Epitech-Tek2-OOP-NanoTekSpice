/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4512.cpp
*/

#include "Component4512.hpp"

nts::Component4512::Component4512() : AComponent(_4512, 15) {
    _excludedPins.push_back(8);
}

nts::Tristate nts::Component4512::compute([[maybe_unused]] std::size_t pin) {
    return Undefined;
}
