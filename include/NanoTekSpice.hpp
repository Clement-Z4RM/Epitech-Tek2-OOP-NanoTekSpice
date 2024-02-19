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
}

#endif /* !NANOTEKSPICE_NANOTEKSPICE_HPP_ */
