/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component2716.hpp
*/

#ifndef COMPONENT2716_HPP
#define COMPONENT2716_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component2716 : public AComponent {
    public:
        Component2716();
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENT2716_HPP
