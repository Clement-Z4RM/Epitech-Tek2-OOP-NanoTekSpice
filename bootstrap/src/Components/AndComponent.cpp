/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** AndComponent.cpp
*/

#include "Components/AndComponent.hpp"

nts::Tristate nts::AndComponent::compute(std::size_t pin) {
    Link link1 = _links.at(1);
    Link link2 = _links.at(2);

    switch (pin) {
        case 1:
            return link1.other.compute(link1.otherPin);
        case 2:
            return link2.other.compute(link2.otherPin);
        case 3:
            return link1.other.compute(link1.otherPin) && link2.other.compute(link2.otherPin);
        default:
            return Undefined;
    }
}
