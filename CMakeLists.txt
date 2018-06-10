cmake_minimum_required(VERSION 3.10)
project(SeaBattle)

set(CMAKE_CXX_STANDARD 11)

add_executable( SeaBattle
        src/main.cpp
        include/Intellect.h
        src/UserIntellect.cpp
        include/UserIntellect.h
        src/PresentationController.cpp
        include/PresentationController.h
        src/InputController.cpp
        include/InputController.h
        src/ComputerIntellect.cpp
        include/ComputerIntellect.h)