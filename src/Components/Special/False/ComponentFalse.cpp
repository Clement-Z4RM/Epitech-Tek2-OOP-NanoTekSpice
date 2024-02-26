/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentFalse.cpp
*/

#include "ComponentFalse.hpp"

nts::ComponentFalse::ComponentFalse() : AComponent(_false, 1) {}

nts::Tristate nts::ComponentFalse::compute(std::size_t pin) {
    if (pin == 1)
        return False;
    return Undefined;
}
