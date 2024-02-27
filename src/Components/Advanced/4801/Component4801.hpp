/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4801.hpp
*/

#ifndef COMPONENT4801_HPP
#define COMPONENT4801_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4801 : public AComponent {
    public:
        Component4801();
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT4801_HPP
