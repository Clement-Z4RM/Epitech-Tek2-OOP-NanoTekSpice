/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4069.hpp
*/

#ifndef COMPONENT4069_HPP
#define COMPONENT4069_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4069 : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4069_HPP
