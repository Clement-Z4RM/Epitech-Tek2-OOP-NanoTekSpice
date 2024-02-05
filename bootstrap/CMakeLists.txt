cmake_minimum_required(VERSION 3.27)
project(bootstrap)

set(CMAKE_CXX_STANDARD 20)

include_directories(src include)

add_executable(bootstrap
        src/Components/AComponent.cpp
        include/Components/AComponent.hpp
        include/Components/IComponent.hpp
        src/main.cpp
        src/Components/TrueComponent.cpp
        include/Components/TrueComponent.hpp
        src/Components/FalseComponent.cpp
        include/Components/FalseComponent.hpp
        src/Components/AndComponent.cpp
        include/Components/AndComponent.hpp
        src/Components/NotComponent.cpp
        include/Components/NotComponent.hpp
        src/Components/IComponent.cpp
)
