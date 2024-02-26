/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4071.hpp
*/

#ifndef COMPONENT4071_HPP
#define COMPONENT4071_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4071 : public AComponent {
    public:
        Component4071();

        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4071_HPP
