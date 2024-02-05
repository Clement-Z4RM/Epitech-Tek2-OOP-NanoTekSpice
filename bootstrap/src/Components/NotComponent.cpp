/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** NotComponent.cpp
*/

#include "Components/NotComponent.hpp"

nts::Tristate nts::NotComponent::compute(std::size_t pin) {
    Link link = _links.at(1);

    switch (pin) {
        case 1:
            return link.other.compute(link.otherPin);
        case 2:
            return !link.other.compute(link.otherPin);
        default:
            return Undefined;
    }
}
