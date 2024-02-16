/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit.cpp
*/

#include <utility>
#include <regex>
#include "../Utilities/Utilities.hpp"
#include "../Components/Factory/ComponentsFactory.hpp"
#include "Circuit.hpp"

const std::string nts::Circuit::Error::ERRORS[] = {
        "The specified configuration is invalid (no file open)",
        "Unknown part name",
        "Unknown component type",
        "Unknown component name",
        "Invalid chipset line format",
        "Invalid link line format",
        "No chipset found in the configuration file"
};

nts::Circuit::Error::Error(std::string message) : _message(std::move(message)) {}

const char *nts::Circuit::Error::what() const noexcept {
    return _message.c_str();
}

nts::Circuit::Circuit() : _isLoaded(false) {
    // TODO: Can parts be inverted?
    _partsFunctions["chipsets"] = &nts::Circuit::_chipsetFunction;
    _partsFunctions["links"] = &nts::Circuit::_linkFunction;
}

nts::Circuit::Circuit(nts::Config &config) : Circuit() {
    loadConfig(config);
}

bool nts::Circuit::isLoaded() const {
    return _isLoaded;
}

void nts::Circuit::loadConfig(nts::Config &config) {
    if (!config.isOpen())
        throw Error(Error::ERRORS[Error::ClosedFileConfig]);

    std::ifstream &file = config.getFile();
    std::string currentPart;
    std::vector<std::string> tokens;
    std::string buffer;
    std::string::size_type hashtagIndex;

    while (std::getline(file, buffer)) {
        hashtagIndex = buffer.find('#');
        if (hashtagIndex != std::string::npos) {
            buffer[hashtagIndex] = '\0';
            buffer.resize(hashtagIndex);
        }
        if (buffer.empty() || std::regex_match(buffer, std::regex("^[[:blank:]]+$")))
            continue;
        if (buffer.starts_with('.') && buffer.ends_with(':')) {
            currentPart = buffer.substr(1, buffer.size() - 2);
            if (_partsFunctions.find(currentPart) == _partsFunctions.end())
                throw Error(Error::ERRORS[Error::UnknownPart] + " '" + currentPart + "'");
            continue;
        }
        (this->*(_partsFunctions[currentPart]))(buffer);
    }
    if (_chipsets.empty())
        throw Error(Error::ERRORS[Error::NoChipset]);
    // TODO: Error if no link/a chipset is not linked/no path from input to output...?
    _isLoaded = true;
}

void nts::Circuit::_chipsetFunction(const std::string &line) {
    if (!std::regex_match(line, std::regex(R"(^[[:blank:]]*[[:alnum:]]{2,}[[:blank:]]+[[:alnum:]]+[[:blank:]]*$)")))
        throw Error(Error::ERRORS[Error::InvalidChipsetLineFormat] + " '" + line + "'");

    std::vector<std::string> tokens = Utilities::splitLine(line);
    if (!ComponentsFactory::isComponentExists(tokens[COMPONENT]))
        throw Error(Error::ERRORS[Error::UnknownComponentType] + " '" + tokens[COMPONENT] + "'");
    if (_chipsets.contains(tokens[NAME]))
        throw Error("Component '" + tokens[NAME] + "' already exists");
    _chipsets[tokens[NAME]] = ComponentsFactory::createComponent(tokens[COMPONENT]);
}

void nts::Circuit::_linkFunction([[maybe_unused]] const std::string &line) {
    if (!std::regex_match(line, std::regex(R"(^[[:blank:]]*[[:alnum:]]+:\d+[[:blank:]]+[[:alnum:]]+:\d+[[:blank:]]*$)")))
        throw Error(Error::ERRORS[Error::InvalidLinkLineFormat] + " '" + line + "'");

    std::vector<std::string> tokens = Utilities::splitLine(line);
    std::vector<std::string> pin1 = Utilities::splitLine(tokens[PIN_1], ':');
    std::vector<std::string> pin2 = Utilities::splitLine(tokens[PIN_2], ':');
    if (!_chipsets.contains(pin1[NAME]))
        throw Error(Error::ERRORS[Error::UnknownComponentName] + " '" + pin1[NAME] + "'");
    if (!_chipsets.contains(pin2[NAME]))
        throw Error(Error::ERRORS[Error::UnknownComponentName] + " '" + pin1[NAME] + "'");
    // TODO: Implement link
}
