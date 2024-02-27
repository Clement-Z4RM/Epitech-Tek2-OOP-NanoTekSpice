/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4040.cpp
*/

#include "Component4040.hpp"

nts::Component4040::Component4040() : AComponent(_4040, 16){
}

nts::Tristate nts::Component4040::compute([[maybe_unused]]std::size_t pin) {
    return nts::True;
}
