/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit.hpp
*/

#ifndef NANOTEKSPICE_CIRCUIT_HPP_
#define NANOTEKSPICE_CIRCUIT_HPP_

#include <exception>
#include <functional>
#include <memory>
#include <unordered_map>
#include "../Parsing/Config/Config.hpp"
#include "IComponent.hpp"

#define COMPONENT_TYPE 0
#define COMPONENT_NAME 1
#define PIN_1          0
#define PIN_2          1
#define NAME           0
#define PIN            1

namespace nts {
    class Circuit {
    public:
        class Error : public std::exception {
        public:
            enum ErrorType {
                LoadedConfig,
                NotLoadedConfig,
                ClosedFileConfig,
                LineBeforePart,
                UnknownPart,
                UnknownComponentType,
                UnknownComponentName,
                InvalidChipsetLineFormat,
                InvalidLinkLineFormat,
                LinkToItself,
                InputLinkedToInput,
                OutputLinkedToOutput,
                NoChipset
            };

            static const std::string ERRORS[];

            explicit Error(std::string message);

            [[nodiscard]] const char *what() const noexcept override;

        private:
            const std::string _message;
        };

    public:
        Circuit();

        explicit Circuit(Config &config);

        [[nodiscard]] bool isLoaded() const;

        [[nodiscard]] const std::map<std::string, std::unique_ptr<IComponent>> &getComponents() const;

        [[nodiscard]] unsigned int getTick() const;

        void loadConfig(Config &config);

        [[nodiscard]] bool containsComponent(const std::string &name) const;

        void setInputValue(const std::string &componentName, char value);

        void simulate(bool incrementTick = true);

    private:
        bool _isLoaded = false;
        std::unordered_map<std::string, void (Circuit::*)(const std::string &)> _partsFunctions;

        std::map<std::string, std::unique_ptr<IComponent>> _components;

        unsigned int _tick = 0;

        void _chipsetFunction(const std::string &line);

        void _linkFunction(const std::string &line);
    };
}

#endif /* !NANOTEKSPICE_CIRCUIT_HPP_ */
