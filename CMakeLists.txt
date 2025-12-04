
cmake_minimum_required(VERSION 3.16)
project(hello_ninja LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable some useful warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(hello_ninja main.cpp)

# ---- tests ----
enable_testing()
add_executable(hello_ninja_tests tests/test_sum.cpp)
add_test(NAME hello_ninja_tests COMMAND hello_ninja_tests)
