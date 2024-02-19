cmake_minimum_required(VERSION 3.27)
project(NanoTekSpice)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(NANOTEKSPICE_SOURCES
        src/Main.cpp
        src/NanoTekSpice.cpp
        src/Components/Elementary/And/ComponentAnd.cpp
        src/Components/Elementary/And/ComponentAnd.hpp
        src/Components/AComponent.cpp
        src/Components/AComponent.hpp
        src/Components/IComponent.cpp
        src/Components/IComponent.hpp
        src/Components/Elementary/Not/ComponentNot.cpp
        src/Components/Elementary/Not/ComponentNot.hpp
        src/Components/Special/False/ComponentFalse.cpp
        src/Components/Special/False/ComponentFalse.hpp
        src/Components/Special/True/ComponentTrue.cpp
        src/Components/Special/True/ComponentTrue.hpp
        src/Components/Elementary/Or/ComponentOr.cpp
        src/Components/Elementary/Or/ComponentOr.hpp
        src/Components/Elementary/Xor/ComponentXor.cpp
        src/Components/Elementary/Xor/ComponentXor.hpp
        src/Components/Special/Input/ComponentInput.cpp
        src/Components/Special/Input/ComponentInput.hpp
        src/Components/Special/Output/ComponentOutput.cpp
        src/Components/Special/Output/ComponentOutput.hpp
        src/Components/Special/Clock/ComponentClock.cpp
        src/Components/Special/Clock/ComponentClock.hpp
        src/Components/Gates/4001/Component4001.cpp
        src/Components/Gates/4001/Component4001.hpp
        src/Components/Gates/4011/Component4011.cpp
        src/Components/Gates/4011/Component4011.hpp
        src/Components/Gates/4030/Component4030.cpp
        src/Components/Gates/4030/Component4030.hpp)

set(UNIT_TESTS_SOURCES
        tests/test_or_gate.cpp
        tests/test_clock.cpp
        tests/test_bad.cpp
        tests/test_no_argument.cpp
        src/Components/Elementary/Or/ComponentOr.cpp
        src/Components/Elementary/Or/ComponentOr.hpp)

add_executable(nanotekspice ${NANOTEKSPICE_SOURCES})

list(REMOVE_ITEM NANOTEKSPICE_SOURCES src/Main.cpp)

add_executable(unit_tests ${NANOTEKSPICE_SOURCES} ${UNIT_TESTS_SOURCES})

target_link_libraries(unit_tests PRIVATE criterion gcov)
