/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4512.hpp
*/

#ifndef COMPONENT4512_HPP
#define COMPONENT4512_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4512 : public AComponent {
    public:
        Component4512();
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4512_HPP
