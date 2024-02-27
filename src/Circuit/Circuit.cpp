/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit.cpp
*/

#include <utility>
#include <iostream>
#include <regex>
#include "../Utilities/Utilities.hpp"
#include "../Components/AComponent.hpp"
#include "../Components/Factory/ComponentsFactory.hpp"
#include "Circuit.hpp"

const std::string nts::Circuit::Error::ERRORS[] = {
        "The configuration is already loaded",
        "The configuration is not loaded",
        "The specified configuration is invalid (no file open)",
        "Configuration line before part",
        "Unknown part name",
        "Unknown component type",
        "Unknown component name",
        "Invalid chipset line format",
        "Invalid link line format",
        "Pin linked to itself",
        "Input linked to another input",
        "Output linked to another output",
        "No chipset found in the configuration file"
};

nts::Circuit::Error::Error(std::string message) : _message(std::move(message)) {}

const char *nts::Circuit::Error::what() const noexcept {
    return _message.c_str();
}

nts::Circuit::Circuit() : _isLoaded(false), _tick(0) {
    _partsFunctions["chipsets"] = &nts::Circuit::_chipsetFunction;
    _partsFunctions["links"] = &nts::Circuit::_linkFunction;
}

nts::Circuit::Circuit(nts::Config &config) : Circuit() {
    loadConfig(config);
}

bool nts::Circuit::isLoaded() const {
    return _isLoaded;
}

const std::map<std::string, std::unique_ptr<nts::IComponent>> &nts::Circuit::getComponents() const {
    if (!_isLoaded)
        throw Error(Error::ERRORS[Error::NotLoadedConfig]);
    return _components;
}

unsigned int nts::Circuit::getTick() const {
    if (!_isLoaded)
        throw Error(Error::ERRORS[Error::NotLoadedConfig]);
    return _tick;
}

void nts::Circuit::loadConfig(nts::Config &config) {
    if (_isLoaded)
        throw Error(Error::ERRORS[Error::LoadedConfig]);
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
        buffer = Utilities::trim(buffer);
        if (buffer.empty())
            continue;
        if (buffer.starts_with('.') && buffer.ends_with(':')) {
            currentPart = buffer.substr(1, buffer.size() - 2);
            if (_partsFunctions.find(currentPart) == _partsFunctions.end())
                throw Error(Error::ERRORS[Error::UnknownPart] + " '" + currentPart + "'");
            continue;
        }
        if (currentPart.empty())
            throw Error(Error::ERRORS[Error::LineBeforePart]);
        (this->*(_partsFunctions[currentPart]))(buffer);
    }
    if (_components.empty())
        throw Error(Error::ERRORS[Error::NoChipset]);
    // TODO: Error if no link/a chipset is not linked/no path from input to output/no input and or output/...?
    _isLoaded = true;
}

void nts::Circuit::_chipsetFunction(const std::string &line) {
    if (!std::regex_match(line, std::regex(R"(^\w+[[:blank:]]+\w+$)")))
        throw Error(Error::ERRORS[Error::InvalidChipsetLineFormat] + " '" + line + "'");

    std::vector<std::string> tokens = Utilities::splitLine(line);
    if (!ComponentsFactory::isValidComponentType(tokens[COMPONENT_TYPE]))
        throw Error(Error::ERRORS[Error::UnknownComponentType] + " '" + tokens[COMPONENT_TYPE] + "'");
    if (_components.contains(tokens[COMPONENT_NAME]))
        throw Error("Component '" + tokens[COMPONENT_NAME] + "' already exists");
    _components[tokens[COMPONENT_NAME]] = ComponentsFactory::createComponent(tokens[COMPONENT_TYPE]);
}

void nts::Circuit::_linkFunction(const std::string &line) {
    if (!std::regex_match(line, std::regex(R"(^\w+:\d+[[:blank:]]+\w+:\d+$)")))
        throw Error(Error::ERRORS[Error::InvalidLinkLineFormat] + " '" + line + "'");

    std::vector<std::string> tokens = Utilities::splitLine(line);
    if (tokens[PIN_1] == tokens[PIN_2])
        throw Error(Error::ERRORS[Error::LinkToItself] + ": '" + tokens[PIN_1] + "'");

    std::vector<std::string> pin1 = Utilities::splitLine(tokens[PIN_1], ':');
    std::vector<std::string> pin2 = Utilities::splitLine(tokens[PIN_2], ':');
    if (!_components.contains(pin1[NAME]))
        throw Error(Error::ERRORS[Error::UnknownComponentName] + " '" + pin1[NAME] + "'");
    if (!_components.contains(pin2[NAME]))
        throw Error(Error::ERRORS[Error::UnknownComponentName] + " '" + pin1[NAME] + "'");

    std::unique_ptr<IComponent> &component1 = _components.at(pin1[NAME]);
    std::unique_ptr<IComponent> &component2 = _components.at(pin2[NAME]);

    if (component1->getType() == _input && component2->getType() == _input)
        throw Error(Error::ERRORS[Error::InputLinkedToInput] + ": '" + pin1[NAME] + "' and '" + pin2[NAME] + "'");
    else if (component1->getType() == _output && component2->getType() == _output)
        throw Error(Error::ERRORS[Error::OutputLinkedToOutput] + ": '" + pin1[NAME] + "' and '" + pin2[NAME] + "'");

    try {
        component1->setLink(std::stoi(pin1[PIN]), component2, std::stoi(pin2[PIN]));
    } catch (AComponent::Error &exception) {
        throw Error(exception.what() + std::string(": '") + line + "'");
    }
}

bool nts::Circuit::containsComponent(const std::string &name) const {
    if (!_isLoaded)
        throw Error(Error::ERRORS[Error::NotLoadedConfig]);
    return _components.contains(name);
}

void nts::Circuit::setInputValue(const std::string &componentName, char value) {
    if (!_isLoaded)
        throw Error(Error::ERRORS[Error::NotLoadedConfig]);

    std::unique_ptr<IComponent> &component1 = _components.at(componentName);

    if (component1->getType() != _input && component1->getType() != _clock) {
        std::cerr << "Component '" << componentName << "' is neither an input nor a clock." << std::endl;
        return;
    }

    Tristate state;
    switch (value) {
        case '0':
            state = False;
            break;
        case '1':
            state = True;
            break;
        case 'U':
            state = Undefined;
            break;
        default: // Should never happen (checked in Shell::_changeInputValue)
            return;
    }
    component1->updateState(state);
}

// TODO: Simulate from inputs to outputs
void nts::Circuit::simulate() {
    if (!_isLoaded)
        throw Error(Error::ERRORS[Error::NotLoadedConfig]);
    ++_tick;
    for (const auto &item: _components)
        item.second->simulate(_tick);
}
