/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** tests.hpp
*/

#ifndef NANOTEKSPICE_TESTS_HPP_
#define NANOTEKSPICE_TESTS_HPP_

#ifdef __IS_4069__
#define INPUTS(_1, _3, _5, _9, _11, _13) \
    "input(s):\n  in_01: " #_1 "\n  in_03: " #_3 "\n  in_05: " #_5 "\n  in_09: " #_9 "\n  in_11: " #_11 "\n  in_13: " #_13 "\n"
#define OUTPUTS(_2, _4, _6, _8, _10, _12) \
    "output(s):\n  out_02: " #_2 "\n  out_04: " #_4 "\n  out_06: " #_6 "\n  out_08: " #_8 "\n  out_10: " #_10 "\n  out_12: " #_12 "\n"
#else
#define INPUTS(_1, _2, _5, _6, _8, _9, _12, _13) \
    "input(s):\n  in_01: " #_1 "\n  in_02: " #_2 "\n  in_05: " #_5 "\n  in_06: " #_6 "\n  in_08: " #_8 "\n  in_09: " #_9 "\n  in_12: " #_12 "\n  in_13: " #_13 "\n"
#define OUTPUTS(_3, _4, _10, _11) \
    "output(s):\n  out_03: " #_3 "\n  out_04: " #_4 "\n  out_10: " #_10 "\n  out_11: " #_11 "\n"
#endif

#endif /* !NANOTEKSPICE_TESTS_HPP_ */
