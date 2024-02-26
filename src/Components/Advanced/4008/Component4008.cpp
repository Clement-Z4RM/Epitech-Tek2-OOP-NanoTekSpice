/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4008.cpp
*/

#include "Component4008.hpp"

nts::Component4008::Component4008() : AComponent(_4008, 18){
    _excludedPins.push_back(9);
    _excludedPins.push_back(10);
}

nts::Tristate nts::Component4008::compute(std::size_t pin) {
    if (pin >= 11 && pin <= 18) {
        Tristate input1 = getLink(1);
        Tristate input2 = getLink(2);
        Tristate input3 = getLink(3);
        Tristate input4 = getLink(4);
        auto sum = static_cast<Tristate>((input1 ^ input2) ^ (input3 ^ input4));
        Tristate deduction1 = (input1 && input2) || ((input1 || input2) && (input3 && input4));
        Tristate deduction2 = (input3 && input4);
        Tristate final_deduction = (deduction1 || deduction2) && !(deduction1 && deduction2);

        switch (pin) {
            case 11:
                return sum;
            case 12:
                return final_deduction;
            default:
                return Undefined;
        }
    } else
        return Undefined;
}
