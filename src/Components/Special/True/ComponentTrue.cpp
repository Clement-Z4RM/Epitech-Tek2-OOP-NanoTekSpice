/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentTrue.cpp
*/

#include "ComponentTrue.hpp"

nts::Tristate nts::ComponentTrue::compute(std::size_t pin) {
    if (pin == 1)
        return True;
    return Undefined;
}
