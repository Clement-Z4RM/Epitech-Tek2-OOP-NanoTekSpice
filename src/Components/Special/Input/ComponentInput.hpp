/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentInput.hpp
*/

#ifndef COMPONENTINPUT_HPP
#define COMPONENTINPUT_HPP

#include "../../AComponent.hpp"

namespace nts {
    class ComponentInput : public AComponent {
    public:
        ComponentInput();

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENTINPUT_HPP
