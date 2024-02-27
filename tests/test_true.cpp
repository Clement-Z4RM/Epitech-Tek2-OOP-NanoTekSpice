/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** test_true.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <string>
#include <cstdio>
#include "NanoTekSpice.hpp"

static const char *ARGV[] = {"./nanotekspice", "./tests/test_files/special/true.nts"};

static void redirectAllStd() {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(NanoTekSpice, true, .init = redirectAllStd)
{
    FILE *fake_stdin = cr_get_redirected_stdin();

    fprintf(fake_stdin, "display\n"
                        "un=0\n"
                        "in=0\n"
                        "simulate\n"
                        "display\n");
    fclose(fake_stdin);

    cr_assert_eq(nts::NanoTekSpice::run(2, ARGV), 0);

    std::cout.flush();
    std::cerr.flush();

    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "output(s):\n"
                            "  out: 1\n"
                            "> > > > tick: 1\n"
                            "input(s):\n"
                            "output(s):\n"
                            "  out: 1\n"
                            "> ");
    cr_assert_stderr_eq_str("un: Component not found.\n"
                            "Component 'in' is neither an input nor a clock.\n");
}
