/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentTrue.hpp
*/

#ifndef COMPONENTTRUE_HPP_
#define COMPONENTTRUE_HPP_

#include "../../AComponent.hpp"

namespace nts {
    class ComponentTrue : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !COMPONENTTRUE_HPP_ */
