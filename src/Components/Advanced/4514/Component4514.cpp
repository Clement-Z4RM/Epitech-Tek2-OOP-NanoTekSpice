/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4514.cpp
*/

#include "Component4514.hpp"

nts::Component4514::Component4514() : AComponent(_4514, 24){
}

nts::Tristate nts::Component4514::compute([[maybe_unused]]std::size_t pin) {
    return nts::True;
}
