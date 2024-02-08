/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** True.hpp
*/

#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_

#include "../../AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !TRUECOMPONENT_HPP_ */
