cmake_minimum_required(VERSION 3.10)
project(FiguresProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
    src/main.cpp
)

# Create executable
add_executable(figures_project ${SOURCES})

# Compiler flags
target_compile_options(figures_project PRIVATE -Wall -Wextra -Wpedantic)

# Tests
enable_testing()

set(TEST_SOURCES
    tests/test_figures.cpp
)

add_executable(tests ${TEST_SOURCES} ${SOURCES})
target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)
add_test(NAME FiguresTests COMMAND tests)
