cmake_minimum_required(VERSION 3.10)
project(laba3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем папку с заголовочными файлами
include_directories(include)

# Основная программа
add_executable(${PROJECT_NAME}
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
    src/main.cpp
)

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

# Ищем и подключаем GTest
find_package(GTest REQUIRED)
target_link_libraries(tests GTest::gtest GTest::gtest_main pthread)

# Добавляем тест
add_test(NAME FiguresTests COMMAND tests)
