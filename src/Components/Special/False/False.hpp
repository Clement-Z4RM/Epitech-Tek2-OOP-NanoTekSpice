/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** False.hpp
*/

#ifndef FALSECOMPONENT_HPP_
#define FALSECOMPONENT_HPP_

#include "../../AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !FALSECOMPONENT_HPP_ */
