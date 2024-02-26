/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentTrue.cpp
*/

#include "ComponentTrue.hpp"

nts::ComponentTrue::ComponentTrue() : AComponent(_true, 1) {}

nts::Tristate nts::ComponentTrue::compute(std::size_t pin) {
    if (pin == 1)
        return True;
    return Undefined;
}
