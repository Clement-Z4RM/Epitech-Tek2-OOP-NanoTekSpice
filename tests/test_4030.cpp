/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** test_4030.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "NanoTekSpice.hpp"
#include "tests.hpp"

static const char *ARGV[] = {"./nanotekspice", "./tests/test_files/gates/4030_xor.nts"};

static void redirectAllStd() {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(NanoTekSpice, 4030, .init = redirectAllStd)
{
    FILE *fake_stdin = cr_get_redirected_stdin();
    std::ifstream file("tests/test_files/gates/input.txt");
    std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    fprintf(fake_stdin, "%s", buffer.c_str());
    fclose(fake_stdin);
    file.close();

    cr_assert_eq(nts::NanoTekSpice::run(2, ARGV), 0);

    std::cout.flush();
    std::cerr.flush();

    cr_assert_stdout_eq_str("> tick: 0\n"
                            INPUTS(U, U, U, U, U, U, U, U)
                            OUTPUTS(U, U, U, U)
                            "> > > > tick: 1\n"
                            INPUTS(1, U, U, U, U, U, U, U)
                            OUTPUTS(U, U, U, U)
                            "> > > > tick: 2\n"
                            INPUTS(1, 0, U, U, U, U, U, U)
                            OUTPUTS(1, U, U, U)
                            "> > > > tick: 3\n"
                            INPUTS(1, 1, U, U, U, U, U, U)
                            OUTPUTS(0, U, U, U)
                            "> > > > tick: 4\n"
                            INPUTS(1, 1, 1, U, U, U, U, U)
                            OUTPUTS(0, U, U, U)
                            "> > > > tick: 5\n"
                            INPUTS(1, 1, 1, 0, U, U, U, U)
                            OUTPUTS(0, 1, U, U)
                            "> > > > tick: 6\n"
                            INPUTS(1, 1, 1, 1, U, U, U, U)
                            OUTPUTS(0, 0, U, U)
                            "> > > > tick: 7\n"
                            INPUTS(1, 1, 1, 1, 1, U, U, U)
                            OUTPUTS(0, 0, U, U)
                            "> > > > tick: 8\n"
                            INPUTS(1, 1, 1, 1, 1, 0, U, U)
                            OUTPUTS(0, 0, 1, U)
                            "> > > > tick: 9\n"
                            INPUTS(1, 1, 1, 1, 1, 1, U, U)
                            OUTPUTS(0, 0, 0, U)
                            "> > > > tick: 10\n"
                            INPUTS(1, 1, 1, 1, 1, 1, 1, U)
                            OUTPUTS(0, 0, 0, U)
                            "> > > > tick: 11\n"
                            INPUTS(1, 1, 1, 1, 1, 1, 1, 0)
                            OUTPUTS(0, 0, 0, 1)
                            "> > > > tick: 12\n"
                            INPUTS(1, 1, 1, 1, 1, 1, 1, 1)
                            OUTPUTS(0, 0, 0, 0)
                            "> > > > tick: 13\n"
                            INPUTS(1, 1, U, 1, 1, 1, 1, 1)
                            OUTPUTS(0, U, 0, 0)
                            "> > > > tick: 14\n"
                            INPUTS(1, 1, 0, 1, 1, 1, 1, 1)
                            OUTPUTS(0, 1, 0, 0)
                            "> ");
    cr_assert_stderr_eq_str("");
}
