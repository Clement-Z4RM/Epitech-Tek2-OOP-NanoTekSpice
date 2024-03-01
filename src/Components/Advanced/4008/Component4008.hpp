/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4008.hpp
*/

#ifndef COMPONENT4008_HPP
#define COMPONENT4008_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4008 : public AComponent {
    public:
        Component4008();
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4008_HPP
