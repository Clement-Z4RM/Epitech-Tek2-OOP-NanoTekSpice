/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponent.hpp
*/

#ifndef NANOTEKSPICE_ICOMPONENT_HPP_
#define NANOTEKSPICE_ICOMPONENT_HPP_

#include <cstddef>
#include <memory>
#include <vector>
#include <map>
#include "NanoTekSpice.hpp"

namespace nts {
    struct Link;

    class IComponent {
    public:
        virtual ~IComponent() = default;

        virtual void simulate(std::size_t tick) = 0;
        [[nodiscard]] virtual Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, std::unique_ptr<IComponent> &other, std::size_t otherPin) = 0;

        // Only for inputs and clocks
        virtual void updateState(Tristate state) = 0;
        [[nodiscard]] virtual char getValue() const = 0;

        [[nodiscard]] virtual Component getType() const = 0;
        [[nodiscard]] virtual const std::map<std::size_t, Link> &getLinks() const = 0;
        [[nodiscard]] virtual Tristate getLink(std::size_t pin) const = 0;
        [[nodiscard]] virtual std::size_t getMaxPin() const = 0;
        [[nodiscard]] virtual const std::vector<std::size_t> &getExcludedPins() const = 0;

        virtual void insert(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
    };

    struct Link {
        IComponent &other;
        std::size_t otherPin;
    };
}

#endif /* !NANOTEKSPICE_ICOMPONENT_HPP_ */
