/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** AndComponent.cpp
*/

#include "Components/AndComponent.hpp"
#include <iostream>

nts::Tristate nts::AndComponent::compute(std::size_t pin) {
    Tristate state1 = at(1);
    Tristate state2 = at(2);

    switch (pin) {
        case 1:
            return state1;
        case 2:
            return state2;
        case 3:
            return state1 && state2;
        default:
            return Undefined;
    }
}
