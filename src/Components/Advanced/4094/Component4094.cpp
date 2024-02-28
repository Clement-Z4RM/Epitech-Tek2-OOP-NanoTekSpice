/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4094.cpp
*/

#include "Component4094.hpp"

nts::Component4094::Component4094() : AComponent(_4094, 15) {
    _excludedPins.push_back(8);
}

nts::Tristate nts::Component4094::compute([[maybe_unused]]std::size_t pin) {
    return nts::True;
}
