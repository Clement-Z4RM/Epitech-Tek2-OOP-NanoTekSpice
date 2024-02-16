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

#define COMPONENT 0
#define NAME      1
#define PIN_1     0
#define PIN_2     1
#define PIN       1

namespace nts {
    // TODO: Implement IComponent and uncomment the inheritance (or not, IDK)
    // TODO: throw errors if function is called before loadConfig
    class Circuit /*: public IComponent*/ {
    public:
        class Error : public std::exception {
        public:
            enum ErrorType {
                ClosedFileConfig,
                UnknownPart,
                UnknownComponentType,
                UnknownComponentName,
                InvalidChipsetLineFormat,
                InvalidLinkLineFormat,
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

        void loadConfig(Config &config);

    private:
        bool _isLoaded;
        std::unordered_map<std::string, void (Circuit::*)(const std::string &)> _partsFunctions;

        std::unordered_map<std::string, std::unique_ptr<IComponent>> _chipsets;

        void _chipsetFunction(const std::string &line);

        void _linkFunction(const std::string &line);
    };
}

#endif /* !NANOTEKSPICE_CIRCUIT_HPP_ */
