/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** test_or_gate.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <string>
#include <cstdio>
#include "NanoTekSpice.hpp"

static const char *ARGV[] = {"./nanotekspice", "./tests/test_files/or_gate.nts"};

static void redirectAllStd() {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(NanoTekSpice, or_gate, .init = redirectAllStd)
{
    FILE *fake_stdin = cr_get_redirected_stdin();

    fprintf(fake_stdin, "b=0\n"
                        "a=1\n"
                        "simulate\n"
                        "display\n"
                        "exit\n");
    fclose(fake_stdin);

    cr_assert_eq(nts::NanoTekSpice::run(2, ARGV), 0);

    std::cout.flush();
    std::cerr.flush();

    cr_assert_stdout_eq_str("> > > > "
                            "tick: 1\n"
                            "input(s):\n"
                            "  a: 1\n"
                            "  b: 0\n"
                            "output(s):\n"
                            "  s: 1\n"
                            "> ");
    cr_assert_stderr_eq_str("");
}
