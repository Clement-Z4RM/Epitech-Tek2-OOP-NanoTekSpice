/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentOr.hpp
*/

#ifndef COMPONENTOR_HPP
#define COMPONENTOR_HPP

#include "../../AComponent.hpp"

namespace nts {
    class ComponentOr : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}


#endif //COMPONENTOR_HPP
