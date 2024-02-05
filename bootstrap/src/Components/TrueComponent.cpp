/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** TrueComponent.cpp
*/

#include "Components/TrueComponent.hpp"

nts::Tristate nts::TrueComponent::compute(std::size_t pin) {
    if (pin == 1)
        return True;
    return Undefined;
}
