/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** IComponent.hpp
*/

#ifndef BOOTSTRAP_ICOMPONENT_HPP_
#define BOOTSTRAP_ICOMPONENT_HPP_

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

    struct Link;

    class IComponent {
    public:
        virtual ~IComponent() = default;

        virtual void simulate(std::size_t tick) = 0;
        virtual Tristate compute(std::size_t pin) = 0;
        virtual void insert(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
        virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
        [[nodiscard]] virtual const Tristate at(std::size_t pin) const = 0;

    protected:
        std::map<std::size_t, Link> _links;
    };

    struct Link {
        IComponent &other;
        std::size_t otherPin;
        Tristate state;
    };
}

#endif /* !BOOTSTRAP_ICOMPONENT_HPP_ */
