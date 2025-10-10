# Настройка тестов
if(GTest_FOUND)
    message(STATUS "GTest found, building tests")
    
    # Создаем исполняемый файл для тестов
    add_executable(test_binary test.cpp)
    
    # Линкуем с основным проектом и GTest
    target_link_libraries(test_binary BinaryLib GTest::GTest GTest::Main)
    
    # Добавляем тест в CTest
    add_test(NAME BinaryTests COMMAND test_binary)
    
else()
    message(WARNING "GTest not found, tests will not be built")
endif()
