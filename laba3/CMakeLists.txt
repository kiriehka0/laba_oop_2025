cmake_minimum_required(VERSION 3.10)
project(laba3)  # Явно указываем имя

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Основная программа
add_executable(laba3  # То же имя что и проект
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
    src/main.cpp
)

target_compile_options(laba3 PRIVATE -Wall -Wextra -Wpedantic)

# Тесты
enable_testing()

add_executable(tests
    tests/test_figures.cpp
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
)

# GTest
find_package(GTest REQUIRED)
target_link_libraries(tests GTest::gtest GTest::gtest_main pthread)

add_test(NAME AllTests COMMAND tests)
