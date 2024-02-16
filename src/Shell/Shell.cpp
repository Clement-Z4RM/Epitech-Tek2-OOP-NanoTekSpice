/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Shell.cpp
*/

#include <regex>
#include <iostream>
#include "../Utilities/Utilities.hpp"
#include "Shell.hpp"

const std::unordered_map<std::string, std::function<bool()>> nts::Shell::_commands = {
        {"exit",     nts::Shell::exit},
        {"display",  nts::Shell::display},
        {"simulate", nts::Shell::simulate},
        {"loop",     nts::Shell::loop}
};

void nts::Shell::run() {
    std::string command;

    std::cout << "> ";
    while (std::getline(std::cin, command)) {
        if (executeCommand(Utilities::trim(command)) == EXIT)
            break;
        std::cout << "> ";
    }
}

bool nts::Shell::executeCommand(const std::string &command) {
    if (command.empty())
        return true;
    if (std::regex_match(command, std::regex(R"(^\w+=.*$)"))) {
        changeInputValue();
        return true;
    } else if (_commands.contains(command))
        return _commands.at(command)();
    std::cerr << command << ": Command not found." << std::endl;
    return true;
}

bool nts::Shell::exit() {
    return false;
}

bool nts::Shell::display() {
    return true;
}

// TODO: check if component is an input or a clock, and if value is 0, 1 or U
bool nts::Shell::changeInputValue() {
    return true;
}

bool nts::Shell::simulate() {
    return true;
}

bool nts::Shell::loop() {
    return true;
}
