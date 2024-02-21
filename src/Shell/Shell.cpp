/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Shell.cpp
*/

#include <regex>
#include <iostream>
#include <csignal>
#include "../Utilities/Utilities.hpp"
#include "Shell.hpp"

const std::unordered_map<std::string, std::function<bool(
        nts::Circuit &circuit)>> nts::Shell::_commands = {
        {"exit",     nts::Shell::_exit},
        {"display",  nts::Shell::_display},
        {"simulate", nts::Shell::_simulate},
        {"loop",     nts::Shell::_loop}
};

void nts::Shell::run(Circuit &circuit) {
    std::string command;

    std::cout << "> ";
    while (std::getline(std::cin, command)) {
        if (_executeCommand(Utilities::trim(command), circuit) == EXIT)
            break;
        std::cout << "> ";
    }
}

bool nts::Shell::_executeCommand(const std::string &command, Circuit &circuit) {
    if (command.empty())
        return true;
    if (std::regex_match(command, std::regex(R"(^\w+=.*$)"))) {
        _changeInputValue(command, circuit);
        return true;
    } else if (_commands.contains(command))
        return _commands.at(command)(circuit);
    std::cerr << command << ": Command not found." << std::endl;
    return true;
}

bool nts::Shell::_exit([[maybe_unused]] Circuit &circuit) {
    return false;
}

bool nts::Shell::_display(Circuit &circuit) {
    const std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> &components = circuit.getComponents();

    std::cout << "tick: " << std::endl; // TODO: add tick
    std::cout << "input(s):" << std::endl;
    for (const auto &item: components)
        if (item.second->getType() == _input || item.second->getType() == _clock)
            std::cout << "  " << item.first << ": " << item.second->getValue() << std::endl;
    std::cout << "output(s):" << std::endl;
    for (const auto &item: components)
        if (item.second->getType() == _output)
            std::cout << "  " << item.first << ": " << item.second->getValue() << std::endl;
    return true;
}

bool nts::Shell::_changeInputValue(const std::string &command, Circuit &circuit) {
    std::string::size_type pos = command.find('=');
    std::string input = command.substr(0, pos);
    std::string value = command.substr(pos + 1);

    if (!circuit.containsComponent(input)) {
        std::cerr << input << ": Component not found." << std::endl;
        return true;
    }
    if (value != "0" && value != "1" && value != "U") {
        std::cerr << value << ": Invalid value. Possible values are '0', '1' and 'U'." << std::endl;
        return true;
    }
    circuit.setInputValue(input, value[0]);
    return true;
}

bool nts::Shell::_simulate([[maybe_unused]] Circuit &circuit) {
    return true;
}

volatile bool loop;
bool nts::Shell::_loop([[maybe_unused]] Circuit &circuit) {
    struct sigaction sa{};
    sa.sa_handler = [](int) { loop = false; };
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, nullptr) == -1) {
        std::perror("sigaction");
        return true;
    }

    loop = true;
    while (loop) {
        _simulate(circuit);
        _display(circuit);
        sleep(1);
    }
    sa.sa_handler = SIG_DFL;
    if (sigaction(SIGINT, &sa, nullptr) == -1)
        std::perror("sigaction");
    return true;
}
