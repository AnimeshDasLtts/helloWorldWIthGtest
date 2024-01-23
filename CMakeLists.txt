cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# Include directories for Google Test headers
include_directories(${GTEST_INCLUDE_DIRS})

# Add the executable target for the Hello World application
add_executable(hello_world 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

# Add the executable target for the unit tests
add_executable(test_hello
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_hello.cpp
)

# Link the Google Test library with the test executable
target_link_libraries(test_hello PRIVATE gtest)

# Enable Google Test's automatic discovery of tests
gtest_discover_tests(test_hello)

