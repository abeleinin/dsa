cmake_minimum_required(VERSION 3.15)

# Project name
project(data_structures LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define project directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

# Include the header files directory
include_directories(${INCLUDE_DIR})
include_directories(/opt/homebrew/include/)

# Gather source files for testing
file(GLOB SRC_FILES "${SRC_DIR}/*.cc")
file(GLOB TEST_FILES "${TEST_DIR}/*.cc")

add_library(src_obj OBJECT ${SRC_DIR})

# Find Catch2 for testing
find_package(Catch2 3 REQUIRED)

# Add a testing target
add_executable(test_vector ${TEST_DIR}/test_vector.cc)
add_executable(test_linked_list ${TEST_DIR}/test_linked_list.cc)

# Link Catch2 with the test executable
target_link_libraries(test_vector PRIVATE src_obj Catch2::Catch2WithMain)
target_link_libraries(test_linked_list PRIVATE src_obj Catch2::Catch2WithMain)

enable_testing()
add_test(NAME TestVector COMMAND test_vector)
add_test(NAME TestLinkedList COMMAND test_linked_list)
