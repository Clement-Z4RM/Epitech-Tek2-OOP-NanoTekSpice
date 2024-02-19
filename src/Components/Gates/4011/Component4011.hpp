/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4011.hpp
*/

#ifndef COMPONENT4011_HPP
#define COMPONENT4011_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4011 : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4011_HPP
