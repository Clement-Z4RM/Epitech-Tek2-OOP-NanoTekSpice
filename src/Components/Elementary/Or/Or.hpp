/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Or.hpp
*/

#ifndef OR_HPP
#define OR_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Or : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}


#endif //OR_HPP
