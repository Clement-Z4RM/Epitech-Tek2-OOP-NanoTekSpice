cmake_minimum_required(VERSION 3.27)
project(NanoTekSpice)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(nanotekspice
        src/Main.cpp
        src/NanoTekSpice.cpp)

add_executable(unit_tests
        tests/test_or_gate.cpp
        tests/test_clock.cpp
        tests/test_bad.cpp)
