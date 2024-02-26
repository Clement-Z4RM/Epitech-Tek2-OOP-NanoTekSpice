/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4081.hpp
*/

#ifndef COMPONENT4081_HPP
#define COMPONENT4081_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4081 : public AComponent {
    public:
        Component4081();

        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4081_HPP
