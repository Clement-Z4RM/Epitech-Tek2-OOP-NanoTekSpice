/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** IComponent.cpp
*/

#include "Components/IComponent.hpp"

nts::Tristate nts::operator!(nts::Tristate state) {
    if (state == Undefined)
        return state;
    return state ? False : True;
}

nts::Tristate nts::operator&&(nts::Tristate state1, nts::Tristate state2) {
    if (state1 == Undefined || state2 == Undefined)
        return Undefined;
    if (state1 == False || state2 == False)
        return False;
    return True;
}
