/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Not.hpp
*/

#ifndef NOTCOMPONENT_HPP_
#define NOTCOMPONENT_HPP_

#include "../../AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !NOTCOMPONENT_HPP_ */