# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name, version
project(cmake_example VERSION 1.0.0)

add_library(example_lib myfunc.c)

# Add test
add_executable(example_test test_main.c testcases.c)
target_link_libraries(example_test PRIVATE cunit)
target_link_libraries(example_test PRIVATE example_lib)
# Enable test
enable_testing()
add_test("ExampleTest1" example_test)
