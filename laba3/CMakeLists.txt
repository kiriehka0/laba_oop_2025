cmake_minimum_required(VERSION 3.10)
project(FiguresProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories - ДОБАВИТЬ ЭТИ СТРОКИ
include_directories(include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

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

# Include directories for target - ДОБАВИТЬ ЭТУ СТРОКУ
target_include_directories(figures_project PRIVATE include)

# Tests
enable_testing()

set(TEST_SOURCES
    tests/test_figures.cpp
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
)

add_executable(tests ${TEST_SOURCES})
target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)

# Include directories for tests - ДОБАВИТЬ ЭТУ СТРОКУ
target_include_directories(tests PRIVATE include)

# Find GTest
find_package(GTest REQUIRED)
target_link_libraries(tests GTest::GTest GTest::Main)

add_test(NAME FiguresTests COMMAND tests)
