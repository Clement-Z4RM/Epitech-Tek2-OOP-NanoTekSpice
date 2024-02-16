/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Utilities.cpp
*/

#include <sstream>
#include "Utilities.hpp"

std::vector<std::string> nts::Utilities::splitLine(const std::string &s) {
    std::istringstream iss(s);
    std::vector<std::string> tokens;
    std::string token;

    while (true) {
        iss >> token;
        if (iss.fail())
            break;
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<std::string> nts::Utilities::splitLine(const std::string &s, char delimiter) {
    std::istringstream iss(s);
    std::vector<std::string> tokens;
    std::string token;

    while ((std::getline(iss, token, delimiter)))
        tokens.push_back(token);
    return tokens;
}
