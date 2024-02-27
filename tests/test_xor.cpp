/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** test_xor.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "NanoTekSpice.hpp"

static const char *ARGV[] = {"./nanotekspice", "./tests/test_files/elementary/xor/xor.nts"};

static void redirectAllStd() {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(NanoTekSpice, xor, .init = redirectAllStd)
{
    FILE *fake_stdin = cr_get_redirected_stdin();
    std::ifstream file("tests/test_files/elementary/xor/input.txt");
    std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    fprintf(fake_stdin, "%s", buffer.c_str());
    fclose(fake_stdin);
    file.close();

    cr_assert_eq(nts::NanoTekSpice::run(2, ARGV), 0);

    std::cout.flush();
    std::cerr.flush();

    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > > > > tick: 1\n"
                            "input(s):\n"
                            "  in_1: 0\n"
                            "  in_2: 0\n"
                            "output(s):\n"
                            "  out: 0\n"
                            "> > > > tick: 2\n"
                            "input(s):\n"
                            "  in_1: 0\n"
                            "  in_2: 1\n"
                            "output(s):\n"
                            "  out: 1\n"
                            "> > > > tick: 3\n"
                            "input(s):\n"
                            "  in_1: 0\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > > > > tick: 4\n"
                            "input(s):\n"
                            "  in_1: 1\n"
                            "  in_2: 0\n"
                            "output(s):\n"
                            "  out: 1\n"
                            "> > > > tick: 5\n"
                            "input(s):\n"
                            "  in_1: 1\n"
                            "  in_2: 1\n"
                            "output(s):\n"
                            "  out: 0\n"
                            "> > > > tick: 6\n"
                            "input(s):\n"
                            "  in_1: 1\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > > > > tick: 7\n"
                            "input(s):\n"
                            "  in_1: U\n"
                            "  in_2: 0\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > > > tick: 8\n"
                            "input(s):\n"
                            "  in_1: U\n"
                            "  in_2: 1\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > > > tick: 9\n"
                            "input(s):\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> ");
    cr_assert_stderr_eq_str("");
}
