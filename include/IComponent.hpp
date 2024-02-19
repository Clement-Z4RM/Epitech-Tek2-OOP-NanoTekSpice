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

    enum Component {
        _input,
        _output,
        _true,
        _false,
        _clock,

        _and,
        _or,
        _xor,
        _not,

        _4001,
        _4011,
        _4030,
        _4069,
        _4071,
        _4081,

        _4008,
        _4013,
        _4017,
        _4040,
        _4094,
        _4512,
        _4514,
        _4801,
        _2716,

        _logger
    };

    class IComponent {
    public:
        virtual ~IComponent() = default;

        virtual Component getType() const = 0;

        virtual void simulate(std::size_t tick) = 0;
        virtual Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
    };
}

#endif /* !NANOTEKSPICE_ICOMPONENT_HPP_ */
