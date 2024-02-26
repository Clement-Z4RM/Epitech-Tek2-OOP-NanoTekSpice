/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Shell.hpp
*/

#ifndef NANOTEKSPICE_SHELL_HPP_
#define NANOTEKSPICE_SHELL_HPP_

#include <string>
#include <functional>
#include <unordered_map>
#include "../Circuit/Circuit.hpp"

#define EXIT false

namespace nts {
    class Shell {
    public:
        static void run(Circuit &circuit);

    private:
        static const std::unordered_map<std::string, std::function<bool(Circuit &circuit)>> _commands;

        static bool _executeCommand(const std::string &command, Circuit &circuit);

        static bool _exit(Circuit &circuit);

        static bool _display(Circuit &circuit);

        static bool _changeInputValue(const std::string &command, Circuit &circuit);

        static bool _simulate(Circuit &circuit);

        static bool _loop(Circuit &circuit);
    };
}

#endif /* !NANOTEKSPICE_SHELL_HPP_ */
