# necessary CMake to compile executables with pybind11 modules
cmake_minimum_required(VERSION 3.12)
project(cpp-python)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(pybind11)

add_executable(cpp-python main.cpp)
add_executable(cpp-python-np numpy.cpp)

target_link_libraries(cpp-python PRIVATE pybind11::embed)
target_link_libraries(cpp-python-np PRIVATE pybind11::embed)
