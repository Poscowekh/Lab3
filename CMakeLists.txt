cmake_minimum_required(VERSION 3.5)

project(LAB3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LAB3.exe
    Source/Main/Main.cpp
    #Source/Examples/Example.cpp
    #Source/Interface/Interface.cpp
    #Source/Interface/Manual.cpp
    #Source/Tests/Main/TestMain.cpp
    #Source/Utility/DataTypes/Complex.cpp
    #Source/Utility/Randomization/RandomGen.cpp
)

include_directories(headers)

