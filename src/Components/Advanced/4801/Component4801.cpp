/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4801.cpp
*/

#include "Component4801.hpp"

nts::Component4801::Component4801() : AComponent(_4801, 24){
}

nts::Tristate nts::Component4801::compute([[maybe_unused]] std::size_t pin) {
    return Undefined;
}
