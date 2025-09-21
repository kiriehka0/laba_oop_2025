find_package(GTest REQUIRED)

add_executable(run_tests 
    test_closet_pair.cpp
    ../src/closet_pair.cpp  
)

target_link_libraries(run_tests 
    PRIVATE 
        GTest::gtest 
        GTest::gtest_main
)

target_include_directories(run_tests PRIVATE ../include)
