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

#define EXIT false

namespace nts {
    // TODO: change commands type
    class Shell {
    public:
        static void run();

    private:
        static const std::unordered_map<std::string, std::function<bool()>> _commands;

        static bool executeCommand(const std::string &command);

        static bool exit();

        static bool display();

        static bool changeInputValue();

        static bool simulate();

        static bool loop();
    };
}

#endif /* !NANOTEKSPICE_SHELL_HPP_ */
