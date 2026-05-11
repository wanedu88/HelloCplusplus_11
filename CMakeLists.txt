cmake_minimum_required(VERSION 3.10...3.28)

project(HelloCplusplus VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_library(HelloLib
    src/Hello.cpp
)

target_include_directories(HelloLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(HelloCplusplus
    src/main.cpp
)

target_link_libraries(HelloCplusplus PRIVATE
    HelloLib
)

add_subdirectory(googletest-1.16.0)

add_executable(HelloCplusplusTests
    tests/test_hello.cpp
)

target_link_libraries(HelloCplusplusTests PRIVATE
    gtest_main
    HelloLib
)

target_include_directories(HelloCplusplusTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(GoogleTest)
gtest_discover_tests(HelloCplusplusTests)