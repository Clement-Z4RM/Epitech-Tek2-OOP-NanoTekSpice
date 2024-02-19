/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Xor.hpp
*/

#ifndef COMPONENTXOR_HPP
#define COMPONENTXOR_HPP

#include "../../AComponent.hpp"

namespace nts {
    class ComponentXor : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENTXOR_HPP
