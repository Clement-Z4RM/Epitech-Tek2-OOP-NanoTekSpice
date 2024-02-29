/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component4013.cpp
*/

#include "Component4013.hpp"

nts::Component4013::Component4013() : AComponent(_4013, 14) {
    _excludedPins.push_back(7);
    _lastClock1 = Tristate::Undefined;
    _lastClock2 = Tristate::Undefined;
    _state1 = Tristate::Undefined;
    _state2 = Tristate::Undefined;
    _output1 = Tristate::Undefined;
    _output2 = Tristate::Undefined;
}

nts::Tristate nts::Component4013::compute(std::size_t pin) {
    if (pin < 1 || pin > 14)
        return Undefined;

    Tristate clock1 = getLink(3);
    Tristate clock2 = getLink(11);

    if (clock1 == True && _lastClock1 == False) {
        _state1 = getLink(1);
        _output1 = _state1;
    }
    if (clock2 == True && _lastClock2 == False) {
        _state2 = getLink(9);
        _output2 = _state2;
    }
    _lastClock1 = clock1;
    _lastClock2 = clock2;
    if (pin <= 6)
        return _output1;
    else
        return _output2;
}
