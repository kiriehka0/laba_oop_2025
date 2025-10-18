cmake_minimum_required(VERSION 3.10)
project(FiguresProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create library from sources
add_library(figures_lib
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
)

# Include directories for library
target_include_directories(figures_lib PUBLIC include)

# Create executable
add_executable(figures_project src/main.cpp)

# Link library to executable
target_link_libraries(figures_project figures_lib)

# Compiler flags
target_compile_options(figures_project PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(figures_lib PRIVATE -Wall -Wextra -Wpedantic)

# Tests
enable_testing()

add_executable(tests tests/test_figures.cpp)
target_link_libraries(tests figures_lib GTest::GTest GTest::Main)

add_test(NAME FiguresTests COMMAND tests)
