/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** FalseComponent.cpp
*/

#include "Components/FalseComponent.hpp"

nts::Tristate nts::FalseComponent::compute(std::size_t pin) {
    if (pin == 1)
        return False;
    return Undefined;
}
