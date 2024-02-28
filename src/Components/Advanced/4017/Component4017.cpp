/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4017.cpp
*/

#include "Component4017.hpp"

nts::Component4017::Component4017() : AComponent(_4017, 15) {
    _excludedPins.push_back(8);
}

nts::Tristate nts::Component4017::compute([[maybe_unused]] std::size_t pin) {
    return nts::True;
}

