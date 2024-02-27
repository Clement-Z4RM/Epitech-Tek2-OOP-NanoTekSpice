/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** NanoTekSpice.hpp
*/

#ifndef NANOTEKSPICE_NANOTEKSPICE_HPP_
#define NANOTEKSPICE_NANOTEKSPICE_HPP_

#include <string>

namespace nts {
    class NanoTekSpice {
    public:
        static int run(int argc, const char *argv[]);

        static void help(const std::string &programInvocationName);
    };

    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    Tristate operator!(Tristate state);
    Tristate operator&&(Tristate state1, Tristate state2);
    Tristate operator||(Tristate state1, Tristate state2);
    Tristate operator^(Tristate state1, Tristate state2);

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
}

#endif /* !NANOTEKSPICE_NANOTEKSPICE_HPP_ */
