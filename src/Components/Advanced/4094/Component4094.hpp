/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4094.hpp
*/

#ifndef COMPONENT4094_HPP
#define COMPONENT4094_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4094 : public AComponent {
    public:
        Component4094();
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4094_HPP
