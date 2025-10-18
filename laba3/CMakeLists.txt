cmake_minimum_required(VERSION 3.10)
project(laba3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Принудительно устанавливаем флаги компилятора с путями
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${CMAKE_SOURCE_DIR}/include")

# Основная программа
add_executable(laba3
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
    src/main.cpp
)

# Явное указание путей включения
target_include_directories(laba3 PRIVATE ${CMAKE_SOURCE_DIR}/include)
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

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# GTest
find_package(GTest REQUIRED)
target_link_libraries(tests GTest::gtest GTest::gtest_main pthread)

add_test(NAME AllTests COMMAND tests)
