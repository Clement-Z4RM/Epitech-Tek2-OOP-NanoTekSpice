/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** test_bad.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "NanoTekSpice.hpp"

static const char *ARGV[] = {"./nanotekspice", "./tests/test_files/bad.nts"};

static void redirectAllStd() {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(NanoTekSpice, bad, .init = redirectAllStd)
{
    cr_assert_eq(nts::NanoTekSpice::run(ARGV), 84);

    std::cout.flush();
    std::cerr.flush();

    cr_assert_stdout_eq_str("");
    cr_assert_stderr_eq_str("./nanotekspice: \33[3m./tests/test_files/bad.nts\33[0m: Unknown component name\n");
}
