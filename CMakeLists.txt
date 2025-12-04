cmake_minimum_required(VERSION 3.16)
project(hello_ninja LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Library with core logic
add_library(hello_ninja_lib
    math_utils.cpp
)

target_include_directories(hello_ninja_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Main executable
add_executable(hello_ninja
    main.cpp
)

target_link_libraries(hello_ninja
    PRIVATE
        hello_ninja_lib
)

# ---- tests ----
enable_testing()

# Test unitari sul core (math_utils) via eseguibile dedicato
add_executable(hello_ninja_tests
    tests/test_math.cpp   # o tests/test_math.cpp se hai rinominato
)

target_link_libraries(hello_ninja_tests
    PRIVATE
        hello_ninja_lib
)

add_test(NAME unit_hello_ninja_tests COMMAND hello_ninja_tests)

# ---- CLI tests ----
# Verifica che la CLI funzioni come previsto

# 1) comando sum0to9
add_test(NAME cli_sum0to9 COMMAND hello_ninja sum0to9)
set_tests_properties(cli_sum0to9
    PROPERTIES
        PASS_REGULAR_EXPRESSION "Sum 0..9 = 45"
)

# 2) comando sumrange 3 7
add_test(NAME cli_sumrange_3_7 COMMAND hello_ninja sumrange 3 7)
set_tests_properties(cli_sumrange_3_7
    PROPERTIES
        PASS_REGULAR_EXPRESSION "Sum range 3..7 = 25"
)

# 3) comando fact 5
add_test(NAME cli_factorial_5 COMMAND hello_ninja fact 5)
set_tests_properties(cli_factorial_5
    PROPERTIES
        PASS_REGULAR_EXPRESSION "factorial\\(5\\) = 120"
)
