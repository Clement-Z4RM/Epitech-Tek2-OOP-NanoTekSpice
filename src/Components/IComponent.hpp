/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponent.hpp
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <cstddef>
#include <map>

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    Tristate operator!(Tristate state);
    Tristate operator&&(Tristate state1, Tristate state2);
    Tristate operator||(Tristate state1, Tristate state2);

    struct Link;

    class IComponent {
    public:
        virtual ~IComponent() = default;

        virtual void simulate(std::size_t tick) = 0;
        virtual Tristate compute(std::size_t pin) = 0;
        virtual void insert(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
        virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
        [[nodiscard]] virtual Tristate at(std::size_t pin) const = 0;

    protected:
        std::map<std::size_t, Link> _links;
    };

    struct Link {
        IComponent &other;
        std::size_t otherPin;
        Tristate state;
    };
}

#endif /* !ICOMPONENT_HPP_ */
