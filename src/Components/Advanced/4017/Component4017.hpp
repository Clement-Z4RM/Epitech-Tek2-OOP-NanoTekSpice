/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4017.hpp
*/

#ifndef COMPONENT4017_HPP
#define COMPONENT4017_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4017 : public AComponent {
    public:
        Component4017();
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4017_HPP
