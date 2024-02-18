/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Input.cpp
*/

#include "Input.hpp"

nts::Tristate nts::Input::compute(std::size_t pin) {
    if (pin == 1)
        return True;
    return Undefined;
}
