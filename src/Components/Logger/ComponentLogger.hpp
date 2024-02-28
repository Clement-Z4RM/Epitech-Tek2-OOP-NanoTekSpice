/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentLogger.hpp
*/

#ifndef NANOTEKSPICE_COMPONENTLOGGER_HPP_
#define NANOTEKSPICE_COMPONENTLOGGER_HPP_

#include <fstream>
#include "../AComponent.hpp"

#define FILENAME "./log.bin"

namespace nts {
    class ComponentLogger : public AComponent {
    public:
        ComponentLogger();
        ~ComponentLogger() override;

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;

    private:
        Tristate _lastClockState = Undefined;
        std::ofstream _file;

        void _openFile();
    };
}

#endif /* !NANOTEKSPICE_COMPONENTLOGGER_HPP_ */
