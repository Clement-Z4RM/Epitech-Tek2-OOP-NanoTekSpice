/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** test_logger.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <cstdio>
#include "NanoTekSpice.hpp"
#include "../src/Components/Logger/ComponentLogger.hpp"

static const char *ARGV[] = {"./nanotekspice", "./tests/test_files/logger/logger.nts"};

static void redirectAllStd() {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(NanoTekSpice, logger_creates_file_when_inexistant, .init = redirectAllStd)
{
    if (std::filesystem::exists(FILENAME) &&  std::remove(FILENAME))
        cr_assert_fail("remove(\"%s\") failed", FILENAME);

    FILE *fake_stdin = cr_get_redirected_stdin();
    fclose(fake_stdin);

    cr_assert_eq(nts::NanoTekSpice::run(2, ARGV), 0);

    std::cout.flush();
    std::cerr.flush();

    cr_assert_stdout_eq_str("> ");
    cr_assert_stderr_eq_str("");
    cr_assert(std::filesystem::exists(FILENAME));
}

Test(NanoTekSpice, logger_prints_characters, .init = redirectAllStd)
{
    std::ofstream logFile(FILENAME);
    if (!logFile.is_open())
        cr_assert_fail("open(\"%s\") failed", FILENAME);
    logFile.close();

    FILE *fake_stdin = cr_get_redirected_stdin();
    std::ifstream file("tests/test_files/logger/input.txt");
    std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    fprintf(fake_stdin, "%s", buffer.c_str());
    fclose(fake_stdin);
    file.close();

    cr_assert_eq(nts::NanoTekSpice::run(2, ARGV), 0);

    std::cout.flush();
    std::cerr.flush();

    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  clock: U\n"
                            "  in_001: U\n"
                            "  in_002: U\n"
                            "  in_004: U\n"
                            "  in_008: U\n"
                            "  in_016: U\n"
                            "  in_032: U\n"
                            "  in_064: U\n"
                            "  in_128: U\n"
                            "  inhibit: U\n"
                            "output(s):\n"
                            "> > > > > > > > > > > > > > tick: 2\n"
                            "input(s):\n"
                            "  clock: 1\n"
                            "  in_001: 1\n"
                            "  in_002: 1\n"
                            "  in_004: 1\n"
                            "  in_008: 1\n"
                            "  in_016: 0\n"
                            "  in_032: 0\n"
                            "  in_064: 1\n"
                            "  in_128: 0\n"
                            "  inhibit: 0\n"
                            "output(s):\n"
                            "> > > > > tick: 4\n"
                            "input(s):\n"
                            "  clock: 1\n"
                            "  in_001: 1\n"
                            "  in_002: 1\n"
                            "  in_004: 0\n"
                            "  in_008: 1\n"
                            "  in_016: 0\n"
                            "  in_032: 0\n"
                            "  in_064: 1\n"
                            "  in_128: 0\n"
                            "  inhibit: 0\n"
                            "output(s):\n"
                            "> ");
    cr_assert_stderr_eq_str("");

    file.open(FILENAME);
    if (!file.is_open())
        cr_assert_fail("open(\"%s\") failed", FILENAME);

    std::string file_content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    file.close();

    cr_assert_str_eq(file_content.c_str(), "OK");
}
