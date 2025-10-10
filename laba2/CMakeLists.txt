cmake_minimum_required(VERSION 3.14)  # Повышаем для лучшей поддержки GTest
project(BinaryLab)

# Используем C++14 для совместимости с современным GTest
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем папки с исходниками
include_directories(include)

# Находим GTest
find_package(GTest REQUIRED)
message(STATUS "GTest found: ${GTEST_FOUND}")

add_subdirectory(src)
add_subdirectory(tests)
