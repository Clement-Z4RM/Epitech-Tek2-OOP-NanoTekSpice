/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Input.hpp
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Input : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif //INPUT_HPP
