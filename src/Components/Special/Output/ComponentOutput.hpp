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
        Tristate compute(std::size_t pin) override;
        void setValue(Tristate value);
    private:
        Tristate _returnValue = Undefined;
    };
}

#endif //COMPONENTOUTPUT_HPP
