/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Clock.hpp
*/

#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "../../AComponent.hpp"

namespace nts {
    class Clock : public AComponent {
        Tristate compute(std::size_t pin) override;
        void updateState(bool state);
    private:
        bool _state = false;
    };
}

#endif //CLOCK_HPP
