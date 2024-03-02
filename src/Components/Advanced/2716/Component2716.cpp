/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component2716.cpp
*/

#include "Component2716.hpp"

nts::Component2716::Component2716() : AComponent(_2716, 24){
}

nts::Tristate nts::Component2716::compute([[maybe_unused]] std::size_t pin) {
    return Undefined;
}
