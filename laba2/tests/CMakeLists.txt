# Настройка тестов с Google Test
message(STATUS "Configuring tests with GTest")

# Создаем исполняемый файл для тестов
add_executable(test_binary test.cpp)

# Линкуем с основным проектом и GTest
target_link_libraries(test_binary BinaryLib GTest::gtest GTest::gtest_main)

# Добавляем тест в CTest
enable_testing()
add_test(NAME BinaryTests COMMAND test_binary)

# Добавляем цель для удобного запуска
add_custom_target(run_gtest
    COMMAND test_binary
    DEPENDS test_binary
    COMMENT "Running Google Tests..."
)
