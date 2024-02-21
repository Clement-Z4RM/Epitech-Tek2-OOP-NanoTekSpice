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
    // TODO: Implement IComponent and uncomment the inheritance (or not, IDK)
    // TODO: throw errors if function is called before loadConfig
    class Circuit /*: public IComponent*/ {
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

        [[nodiscard]] const std::unordered_map<std::string, std::unique_ptr<IComponent>> &getComponents() const;

        [[nodiscard]] unsigned int getTick() const;

        void loadConfig(Config &config);

        [[nodiscard]] bool containsComponent(const std::string &name) const;

        void setInputValue(const std::string &componentName, char value);

        void simulate();

    private:
        bool _isLoaded;
        std::unordered_map<std::string, void (Circuit::*)(const std::string &)> _partsFunctions;

        // TODO: map for display command (ASCII order)?
        std::unordered_map<std::string, std::unique_ptr<IComponent>> _components;

        unsigned int _tick;

        void _chipsetFunction(const std::string &line);

        void _linkFunction(const std::string &line);
    };
}

#endif /* !NANOTEKSPICE_CIRCUIT_HPP_ */
