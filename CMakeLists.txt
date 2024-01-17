# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# Include directories for CppUTest headers
include_directories(${CPPUTEST_HOME}/include)

# Add the executable target for the Hello World application
add_executable(hello_world 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

# Add the executable target for the unit tests
add_executable(test_hello
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_hello.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/TestHarness.cpp  # Include TestHarness.cpp only for the test_hello executable
)

# Link the CppUTest library with the test executable
target_link_libraries(test_hello PRIVATE CppUTest)

# Enable CppUTest's automatic discovery of tests
add_test(NAME test_hello COMMAND test_hello)
