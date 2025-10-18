cmake_minimum_required(VERSION 3.10)
project(FiguresProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Явное указание путей включения
include_directories(${CMAKE_SOURCE_DIR}/include)

# Основная программа
add_executable(figures_project
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
    src/main.cpp
)

target_compile_options(figures_project PRIVATE -Wall -Wextra -Wpedantic)

# Тесты
enable_testing()

add_executable(test_figures
    tests/test_figures.cpp
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
)

# GTest
find_package(GTest REQUIRED)
target_link_libraries(test_figures GTest::gtest GTest::gtest_main pthread)

add_test(NAME FiguresTests COMMAND test_figures)
