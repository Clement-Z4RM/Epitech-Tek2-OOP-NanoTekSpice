/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentOutput.hpp
*/

#ifndef COMPONENTOUTPUT_HPP
#define COMPONENTOUTPUT_HPP

#include "../../AComponent.hpp"

namespace nts {
    class ComponentOutput : public AComponent {
    public:
        ComponentOutput();

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    };
}

#endif //COMPONENTOUTPUT_HPP
