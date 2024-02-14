cmake_minimum_required(VERSION 3.27)
project(NanoTekSpice)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(NANOTEKSPICE_SOURCES
        src/Main.cpp
        src/NanoTekSpice.cpp
        src/Components/Elementary/And/And.cpp
        src/Components/Elementary/And/And.hpp
        src/Components/AComponent.cpp
        src/Components/AComponent.hpp
        src/Components/IComponent.cpp
        src/Components/IComponent.hpp
        src/Components/Elementary/Not/Not.cpp
        src/Components/Elementary/Not/Not.hpp
        src/Components/Special/False/False.cpp
        src/Components/Special/False/False.hpp
        src/Components/Special/True/True.cpp
        src/Components/Special/True/True.hpp
        src/Components/Elementary/Or/Or.cpp
        src/Components/Elementary/Or/Or.hpp
        src/Components/Elementary/Xor/Xor.cpp
        src/Components/Elementary/Xor/Xor.hpp)

set(UNIT_TESTS_SOURCES
        tests/test_or_gate.cpp
        tests/test_clock.cpp
        tests/test_bad.cpp
        tests/test_no_argument.cpp
        src/Components/Elementary/Or/Or.cpp
        src/Components/Elementary/Or/Or.hpp)

add_executable(nanotekspice ${NANOTEKSPICE_SOURCES})

list(REMOVE_ITEM NANOTEKSPICE_SOURCES src/Main.cpp)

add_executable(unit_tests ${NANOTEKSPICE_SOURCES} ${UNIT_TESTS_SOURCES})

target_link_libraries(unit_tests PRIVATE criterion gcov)
