/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** False.cpp
*/

#include "False.hpp"

nts::Tristate nts::FalseComponent::compute(std::size_t pin) {
    if (pin == 1)
        return False;
    return Undefined;
}
