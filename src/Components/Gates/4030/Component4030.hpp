/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4030.hpp
*/

#ifndef COMPONENT4030_HPP
#define COMPONENT4030_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4030 : public AComponent {
    public:
        Component4030();

        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4030_HPP
