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

        Tristate compute(std::size_t pin) override;

    private:
        Tristate _state = Undefined;
    };
}

#endif //COMPONENTOUTPUT_HPP
