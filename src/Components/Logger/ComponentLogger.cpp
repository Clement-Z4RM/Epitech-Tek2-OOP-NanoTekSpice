/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentLogger.cpp
*/

#include <iostream>
#include "ComponentLogger.hpp"

nts::ComponentLogger::ComponentLogger() : AComponent(_logger, 10) {}

nts::ComponentLogger::~ComponentLogger() {
    if (_file.is_open())
        _file.close();
}

void nts::ComponentLogger::simulate(std::size_t tick) {
    // If tick is not 0 and file is not open, return
    if (tick != 0 && !_file.is_open())
        return;

    Tristate clockState = getLink(9);

    // Open file and initialize last clock state on first tick
    if (tick == 0) {
        _openFile();
        _lastClockState = clockState;
        return;
    }

    // Only do something if inhibit is False and clock is on the positive-going edge
    if (getLink(10) == False && _lastClockState == False && clockState == True) {
        int c = 0;
        for (u_int8_t i = 1; i <= 8; ++i) {
            Tristate state = getLink(i);
            if (state == Undefined)
                return;
            c |= (state << (i - 1));
        }
        char _c = (char)c;
        _file.write(&_c, 1);
    }

    // Update last clock state
    _lastClockState = clockState;
}

nts::Tristate nts::ComponentLogger::compute([[maybe_unused]] std::size_t pin) {
    return nts::Undefined;
}

void nts::ComponentLogger::_openFile() {
    _file.open(FILENAME, std::ios::app);
    if (!_file.is_open())
        std::cerr << "Logger: Could not open " << FILENAME << std::endl;
}
