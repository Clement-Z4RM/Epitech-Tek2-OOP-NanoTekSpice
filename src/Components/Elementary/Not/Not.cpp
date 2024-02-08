/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Not.cpp
*/

#include "Not.hpp"

nts::Tristate nts::NotComponent::compute(std::size_t pin) {
    Tristate state = at(1);

    switch (pin) {
        case 1:
            return state;
        case 2:
            return !state;
        default:
            return Undefined;
    }
}
