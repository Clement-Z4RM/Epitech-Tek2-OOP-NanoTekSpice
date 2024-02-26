/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponent.cpp
*/

#include "IComponent.hpp"

nts::Tristate nts::operator!(nts::Tristate state) {
    if (state == Undefined)
        return state;
    return state ? False : True;
}

nts::Tristate nts::operator&&(nts::Tristate state1, nts::Tristate state2) {
    if (state1 == False || state2 == False)
        return False;
    if (state1 == Undefined || state2 == Undefined)
        return Undefined;
    return True;
}

nts::Tristate nts::operator||(nts::Tristate state1, nts::Tristate state2) {
    if (state1 == True || state2 == True)
        return True;
    if (state1 == Undefined || state2 == Undefined)
        return Undefined;
    return False;
}
