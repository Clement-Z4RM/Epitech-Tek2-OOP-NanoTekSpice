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
        void updateState(bool state);
    private:
        bool _state = false;
    };
}

#endif //COMPONENTCLOCK_HPP
