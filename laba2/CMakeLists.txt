cmake_minimum_required(VERSION 3.10)
project(BinaryLab)

# Повышаем стандарт до C++14 для совместимости с GTest
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем папки с исходниками
include_directories(include)
add_subdirectory(src)

# Проверяем наличие GTest перед добавлением тестов
find_package(GTest)
if(GTest_FOUND)
    add_subdirectory(tests)
else()
    message(WARNING "GTest not found, tests will not be built")
endif()
