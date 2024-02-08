/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** True.cpp
*/

#include "True.hpp"

nts::Tristate nts::TrueComponent::compute(std::size_t pin) {
    if (pin == 1)
        return True;
    return Undefined;
}
