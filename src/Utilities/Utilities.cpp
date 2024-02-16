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

std::string nts::Utilities::trim(const std::string &s) {
    std::string::size_type start = s.find_first_not_of(" \r\t\f\v");
    if (start == std::string::npos)
        return "";

    std::string::size_type end = s.find_last_not_of(" \r\t\f\v");

    return s.substr(start, end - start + 1);
}
