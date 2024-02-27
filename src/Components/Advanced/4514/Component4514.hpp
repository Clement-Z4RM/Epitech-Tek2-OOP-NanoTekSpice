/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4514.hpp
*/

#ifndef COMPONENT4514_HPP
#define COMPONENT4514_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4514 : public AComponent {
    public:
        Component4514();
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4514_HPP
