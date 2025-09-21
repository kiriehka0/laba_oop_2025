cmake_minimum_required(VERSION 3.14)
project(ClosetPairProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(closet_pair_app 
    src/closet_pair.cpp
    src/main.cpp
)
target_include_directories(closet_pair_app PUBLIC include)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests)
    add_subdirectory(tests)
endif()
