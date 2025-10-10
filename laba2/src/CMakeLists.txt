# Создаем основную библиотеку
add_library(BinaryLib binary.cpp)

# Создаем исполняемый файл
add_executable(binary_app main.cpp)
target_link_libraries(binary_app BinaryLib)
