/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** test_no_argument.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "NanoTekSpice.hpp"

static const char *ARGV[] = {"./nanotekspice", nullptr};

static void redirectAllStd() {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(nts, no_argument, .init = redirectAllStd)
{
    cr_assert_eq(nts::NanoTekSpice::run(1, ARGV), 84);

    std::cout.flush();
    std::cerr.flush();

    cr_assert_stdout_eq_str("");
    cr_assert_stderr_eq_str("./nanotekspice: No file provided\n");
}
