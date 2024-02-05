/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** NanoTekSpice.cpp
*/

#include <iostream>
#include "NanoTekSpice.hpp"

int nts::NanoTekSpice::run([[maybe_unused]] const char *argv[]) {
    if (!argv[1]) {
        std::cerr << argv[0] << ": No file provided" << std::endl;
        return 84;
    }
    return 0;
}
