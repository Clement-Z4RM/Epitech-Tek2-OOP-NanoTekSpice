/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Utilities.hpp
*/

#ifndef NANOTEKSPICE_UTILITIES_HPP_
#define NANOTEKSPICE_UTILITIES_HPP_

#include <string>
#include <vector>

namespace nts {
    class Utilities {
    public:
        [[nodiscard]] static std::vector<std::string> splitLine(const std::string &s);

        [[nodiscard]] static std::vector<std::string> splitLine(const std::string &s, char delimiter);
    };
}

#endif /* !NANOTEKSPICE_UTILITIES_HPP_ */
