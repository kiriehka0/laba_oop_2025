cmake_minimum_required(VERSION 3.10)
project(FiguresProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включение директорий
include_directories(include)

# Основная программа
add_executable(figures_project
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
    src/main.cpp
)

# Флаги компилятора
target_compile_options(figures_project PRIVATE -Wall -Wextra -Wpedantic)

# Тесты
enable_testing()

# Исполняемый файл для тестов
add_executable(test_figures
    tests/test_figures.cpp
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
)

# Поиск и подключение GTest
find_package(GTest)
if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
    target_link_libraries(test_figures ${GTEST_LIBRARIES} pthread)
    message(STATUS "GTest found and linked")
else()
    # Попробовать найти вручную
    find_library(GTEST_LIB gtest)
    if(GTEST_LIB)
        target_link_libraries(test_figures ${GTEST_LIB} pthread)
        message(STATUS "GTest library found manually")
    else()
        message(FATAL_ERROR "GTest not found! Install with: sudo apt-get install libgtest-dev")
    endif()
endif()

add_test(NAME FiguresTests COMMAND test_figures)
