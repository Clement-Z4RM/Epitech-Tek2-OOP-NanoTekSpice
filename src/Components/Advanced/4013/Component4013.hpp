/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4013.hpp
*/

#ifndef COMPONENT4013_HPP
#define COMPONENT4013_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Component4013 : public AComponent {
    public:
        Component4013();
        Tristate compute(std::size_t pin) override;
    private:
        Tristate _lastClock1;
        Tristate _lastClock2;
        Tristate _state1;
        Tristate _state2;
        Tristate _output1;
        Tristate _output2;
    };
}

#endif //COMPONENT4013_HPP
