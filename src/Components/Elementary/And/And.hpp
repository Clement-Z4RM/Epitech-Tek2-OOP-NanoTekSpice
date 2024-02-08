/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** And.hpp
*/

#ifndef NANOTEKSPICE_AND_HPP
#define NANOTEKSPICE_AND_HPP

#include "../../AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif //NANOTEKSPICE_AND_HPP
