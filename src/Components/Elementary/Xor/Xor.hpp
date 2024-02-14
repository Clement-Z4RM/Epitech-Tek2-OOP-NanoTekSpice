/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Xor.hpp
*/

#ifndef XOR_HPP
#define XOR_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Xor : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif //XOR_HPP
