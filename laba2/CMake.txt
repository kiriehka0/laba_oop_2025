cmake_minimum_required(VERSION 3.10)
project(BinaryLab)

# Настройка компилятора
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем папки с исходниками
include_directories(include)
add_subdirectory(src)
add_subdirectory(tests)
