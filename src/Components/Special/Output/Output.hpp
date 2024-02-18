/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Output.hpp
*/

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Output : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
        void setValue(Tristate value);
    private:
        Tristate _returnValue = Undefined;
    };
}

#endif //OUTPUT_HPP
