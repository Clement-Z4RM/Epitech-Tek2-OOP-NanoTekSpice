/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponent.hpp
*/

#ifndef NANOTEKSPICE_ICOMPONENT_HPP_
#define NANOTEKSPICE_ICOMPONENT_HPP_

#include <cstddef>
#include <map>

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent {
    public:
        virtual ~IComponent() = default;

        virtual void simulate(std::size_t tick) = 0;
        virtual Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
    };
}

#endif /* !NANOTEKSPICE_ICOMPONENT_HPP_ */
