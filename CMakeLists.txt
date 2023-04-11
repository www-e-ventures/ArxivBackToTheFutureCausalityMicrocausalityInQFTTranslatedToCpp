cmake_minimum_required(VERSION 3.25)
project(5B_MicrocausalityInQFT)

set(CMAKE_CXX_STANDARD 17)

add_executable(5B_MicrocausalityInQFT main.cpp include/point.h include/scalar_field.h include/greens_function.h src/point.cpp src/scalar_field.cpp src/greens_function.cpp)
