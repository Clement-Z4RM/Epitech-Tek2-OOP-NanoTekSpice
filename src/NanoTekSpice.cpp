/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** NanoTekSpice.cpp
*/

#include <iostream>
#include "NanoTekSpice.hpp"
#include "Parsing/Config/Config.hpp"
#include "Circuit/Circuit.hpp"
#include "Shell/Shell.hpp"

//region NanoTekSpice static methods
int nts::NanoTekSpice::run(int argc, const char *argv[]) {
    if (argc == 1) {
        std::cerr << argv[0] << ": No file provided." << std::endl;
        return 84;
    }

    Config config((std::string(argv[0])), std::string(argv[1]));
    if (!config.isOpen())
        return 84;

    Circuit circuit;
    try {
        circuit.loadConfig(config);
    } catch (const Circuit::Error &exception) {
        std::cerr << argv[0] << ": " << config.getFilename() << ": " << exception.what() << "." << std::endl;
        return 84;
    }
    if (!circuit.isLoaded())
        return 84;

    Shell::run(circuit);
    return 0;
}

void nts::NanoTekSpice::help(const std::string &programInvocationName) {
    std::cout << "\33[1mNanoTekSpice - Logic simulator\33[0m" << std::endl << std::endl
              << "Usage: " << programInvocationName << " CONFIG_FILE" << std::endl << std::endl
              << "Description" << std::endl
              << "\tCONFIG_FILE\tFile containing the graph description" << std::endl;
    std::exit(0);
}
//endregion

//region Tristate operators
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
//endregion
