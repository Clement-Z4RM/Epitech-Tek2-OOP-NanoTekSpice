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
        Tristate compute(std::size_t pin) override;

    public:
        ComponentClock();

    private:
        Tristate _state = Undefined;
    };
}

#endif //COMPONENTCLOCK_HPP
