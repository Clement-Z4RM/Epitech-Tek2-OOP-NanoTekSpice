cmake_minimum_required(VERSION 3.27)
project(NanoTekSpice)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(NANOTEKSPICE_SOURCES
        src/Main.cpp
        src/NanoTekSpice.cpp
        src/Parsing/Config/Config.cpp
        src/Parsing/Config/Config.hpp
        src/Circuit/Circuit.cpp
        src/Circuit/Circuit.hpp
        include/IComponent.hpp
        src/Utilities/Utilities.cpp
        src/Utilities/Utilities.hpp
        src/Components/Factory/ComponentsFactory.cpp
        src/Components/Factory/ComponentsFactory.hpp
        src/Shell/Shell.cpp
        src/Shell/Shell.hpp
)

set(UNIT_TESTS_SOURCES
        tests/test_or_gate.cpp
        tests/test_clock.cpp
        tests/test_bad.cpp
        tests/test_no_argument.cpp)

add_executable(nanotekspice ${NANOTEKSPICE_SOURCES})

list(REMOVE_ITEM NANOTEKSPICE_SOURCES src/Main.cpp)

add_executable(unit_tests ${NANOTEKSPICE_SOURCES} ${UNIT_TESTS_SOURCES})

target_link_libraries(unit_tests PRIVATE criterion gcov)
