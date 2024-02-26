/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentAnd.hpp
*/

#ifndef COMPONENTAND_HPP
#define COMPONENTAND_HPP

#include "../../AComponent.hpp"

namespace nts {
    class ComponentAnd : public AComponent {
    public:
        ComponentAnd();

        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENTAND_HPP
