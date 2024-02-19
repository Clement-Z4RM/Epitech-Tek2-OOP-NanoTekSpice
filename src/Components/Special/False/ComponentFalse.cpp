/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentFalse.cpp
*/

#include "ComponentFalse.hpp"

nts::Tristate nts::ComponentFalse::compute(std::size_t pin) {
    if (pin == 1)
        return False;
    return Undefined;
}
