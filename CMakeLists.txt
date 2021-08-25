cmake_minimum_required(VERSION 3.20)
project(morse_code)

set(CMAKE_CXX_STANDARD 20)

add_executable(morse_code main.cpp MorseCode.cpp MorseCode.h)
