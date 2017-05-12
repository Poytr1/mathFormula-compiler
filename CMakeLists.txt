cmake_minimum_required(VERSION 3.6)
project(MathFormula)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES mathFormula.h compiler.cpp mathFormula.cpp)
add_executable(MathFormula ${SOURCE_FILES} mathFormula.h compiler.cpp mathFormula.cpp)