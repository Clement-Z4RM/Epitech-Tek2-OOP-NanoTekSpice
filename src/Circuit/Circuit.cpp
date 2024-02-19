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
        "Pin linked to itself",
        "Input linked to another input",
        "Input linked to output",
        "Output linked to another output",
        "Output linked to input",
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
    // TODO: Error if no link/a chipset is not linked/no path from input to output/no input and or output/...?
    _isLoaded = true;
}

void nts::Circuit::_chipsetFunction(const std::string &line) {
    if (!std::regex_match(line, std::regex(R"(^[[:blank:]]*[[:alnum:]]{2,}[[:blank:]]+\w+[[:blank:]]*$)")))
        throw Error(Error::ERRORS[Error::InvalidChipsetLineFormat] + " '" + line + "'");

    std::vector<std::string> tokens = Utilities::splitLine(line);
    if (!ComponentsFactory::isComponentExists(tokens[COMPONENT_TYPE]))
        throw Error(Error::ERRORS[Error::UnknownComponentType] + " '" + tokens[COMPONENT_TYPE] + "'");
    if (_chipsets.contains(tokens[COMPONENT_NAME]))
        throw Error("Component '" + tokens[COMPONENT_NAME] + "' already exists");
    _chipsets[tokens[COMPONENT_NAME]] = ComponentsFactory::createComponent(tokens[COMPONENT_TYPE]);
}

void nts::Circuit::_linkFunction([[maybe_unused]] const std::string &line) {
    if (!std::regex_match(line, std::regex(R"(^[[:blank:]]*\w+:\d+[[:blank:]]+\w+:\d+[[:blank:]]*$)")))
        throw Error(Error::ERRORS[Error::InvalidLinkLineFormat] + " '" + line + "'");

    std::vector<std::string> tokens = Utilities::splitLine(line);
    if (tokens[PIN_1] == tokens[PIN_2])
        throw Error(Error::ERRORS[Error::LinkToItself] + ": '" + tokens[PIN_1] + "'");

    std::vector<std::string> pin1 = Utilities::splitLine(tokens[PIN_1], ':');
    std::vector<std::string> pin2 = Utilities::splitLine(tokens[PIN_2], ':');
    if (!_chipsets.contains(pin1[NAME]))
        throw Error(Error::ERRORS[Error::UnknownComponentName] + " '" + pin1[NAME] + "'");
    if (!_chipsets.contains(pin2[NAME]))
        throw Error(Error::ERRORS[Error::UnknownComponentName] + " '" + pin1[NAME] + "'");

    std::unique_ptr<IComponent> &component1 = _chipsets.at(pin1[NAME]);
    std::unique_ptr<IComponent> &component2 = _chipsets.at(pin2[NAME]);

    Component type1 = component1->getType();
    if (type1 == _input || type1 == _output)
        switch (component2->getType()) {
            case _input:
                throw Error(Error::ERRORS[type1 == _input ? Error::InputLinkedToInput : Error::OutputLinkedToInput] + ": '" + pin1[NAME] + "' and '" + pin2[NAME] + "'");
            case _output:
                throw Error(Error::ERRORS[type1 == _input ? Error::InputLinkedToOutput : Error::OutputLinkedToOutput] + ": '" + pin1[NAME] + "' and '" + pin2[NAME] + "'");
            default:
                break;
        }

    try {
        component1->setLink(std::stoi(pin1[PIN]), component2, std::stoi(pin2[PIN]));
    } catch (...) {
        // TODO: catch
    }
}
