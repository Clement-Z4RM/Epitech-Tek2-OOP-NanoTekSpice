cmake_minimum_required(VERSION 3.27)
project(NanoTekSpice)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(NANOTEKSPICE_SOURCES
        include/IComponent.hpp
        src/Main.cpp
        src/NanoTekSpice.cpp
        src/Utilities/Utilities.cpp
        src/Utilities/Utilities.hpp
        src/Parsing/Config/Config.cpp
        src/Parsing/Config/Config.hpp
        src/Circuit/Circuit.cpp
        src/Circuit/Circuit.hpp
        src/Shell/Shell.cpp
        src/Shell/Shell.hpp
        src/Components/AComponent.cpp
        src/Components/AComponent.hpp
        src/Components/Elementary/And/ComponentAnd.cpp
        src/Components/Elementary/And/ComponentAnd.hpp
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
        src/Components/Gates/4030/Component4030.hpp
        src/Components/Gates/4069/Component4069.cpp
        src/Components/Gates/4069/Component4069.hpp
        src/Components/Gates/4071/Component4071.cpp
        src/Components/Gates/4071/Component4071.hpp
        src/Components/Gates/4081/Component4081.cpp
        src/Components/Gates/4081/Component4081.hpp
        src/Components/Factory/ComponentsFactory.cpp
        src/Components/Factory/ComponentsFactory.hpp
        src/Components/Advanced/4008/Component4008.cpp
        src/Components/Advanced/4008/Component4008.hpp
        src/Components/Advanced/4013/Component4013.cpp
        src/Components/Advanced/4013/Component4013.hpp
        src/Components/Advanced/4017/Component4017.cpp
        src/Components/Advanced/4017/Component4017.hpp
        src/Components/Advanced/2716/Component2716.cpp
        src/Components/Advanced/2716/Component2716.hpp
        src/Components/Advanced/4040/Component4040.cpp
        src/Components/Advanced/4040/Component4040.hpp
        src/Components/Advanced/4094/Component4094.cpp
        src/Components/Advanced/4094/Component4094.hpp
        src/Components/Advanced/4512/Component4512.cpp
        src/Components/Advanced/4512/Component4512.hpp
        src/Components/Advanced/4514/Component4514.cpp
        src/Components/Advanced/4514/Component4514.hpp
        src/Components/Advanced/4801/Component4801.cpp
        src/Components/Advanced/4801/Component4801.hpp)

set(UNIT_TESTS_SOURCES
        tests/test_or_gate.cpp
        tests/test_clock.cpp
        tests/test_bad.cpp
        tests/test_no_argument.cpp)

add_executable(nanotekspice ${NANOTEKSPICE_SOURCES})

list(REMOVE_ITEM NANOTEKSPICE_SOURCES src/Main.cpp)

add_executable(unit_tests ${NANOTEKSPICE_SOURCES} ${UNIT_TESTS_SOURCES})

target_link_libraries(unit_tests PRIVATE criterion gcov)
