/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentInput.cpp
*/

#include "ComponentInput.hpp"

nts::ComponentInput::ComponentInput() : AComponent(_input, 1) {}

nts::Tristate nts::ComponentInput::compute(std::size_t pin) {
    if (pin == 1)
        return True;
    return Undefined;
}
