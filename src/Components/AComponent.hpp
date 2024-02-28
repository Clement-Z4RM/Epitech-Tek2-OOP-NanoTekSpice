/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AComponent.hpp
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <map>
#include "IComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
    public:
        class Error : public std::exception {
        public:
            enum ErrorType {
                PinOutOfRange,
                PinExcluded,
                PinAlreadyLinked
            };

            static const std::string ERRORS[];

            explicit Error(std::string message);

            [[nodiscard]] const char *what() const noexcept override;

        private:
            const std::string _message;
        };

        explicit AComponent(nts::Component type, std::size_t maxPin, Tristate state = Undefined);

        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, std::unique_ptr<IComponent> &other, std::size_t otherPin) override;

        void updateState(Tristate state) override;
        [[nodiscard]] char getValue() const override;

        [[nodiscard]] Component getType() const override;
        [[nodiscard]] const std::map<std::size_t, Link> &getLinks() const override;
        [[nodiscard]] Tristate getLink(std::size_t pin) const override;
        [[nodiscard]] std::size_t getMaxPin() const override;
        [[nodiscard]] const std::vector<std::size_t> &getExcludedPins() const override;

        void insert(std::size_t pin, IComponent &other, std::size_t otherPin) override;

    protected:
        // Only for inputs, clocks and outputs
        Tristate _nextState = Undefined;
        bool _hasChanged = false;

        Tristate _state;
        std::size_t _tick = 0;

        Component _type;
        std::map<std::size_t, Link> _links;
        std::size_t _maxPin;
        std::vector<std::size_t> _excludedPins;
    };
}

#endif /* !ACOMPONENT_HPP_ */
