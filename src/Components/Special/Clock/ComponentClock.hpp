/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentClock.hpp
*/

#ifndef COMPONENTCLOCK_HPP
#define COMPONENTCLOCK_HPP

#include "../../AComponent.hpp"

namespace nts {
    class ComponentClock : public AComponent {
    public:
        ComponentClock();

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;

    private:
        Tristate _state = Undefined;
        std::size_t _tick = 0;
    };
}

#endif //COMPONENTCLOCK_HPP
