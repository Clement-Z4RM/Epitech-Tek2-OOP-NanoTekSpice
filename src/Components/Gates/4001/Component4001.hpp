/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4001.hpp
*/

#ifndef COMPONENT4001_HPP
#define COMPONENT4001_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4001 : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4001_HPP
