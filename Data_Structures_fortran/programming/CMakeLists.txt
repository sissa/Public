# CMake build for P1.6 code tree
cmake_minimum_required(VERSION 3.16)
project(project VERSION 1.0 LANGUAGES Fortran)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

add_executable(00_hello src/00_hello.f90)

enable_testing()

add_test(NAME Hello
  COMMAND sh -c "exec $<TARGET_FILE:00_hello> < ${PROJECT_SOURCE_DIR}/data/d1_2.dat")
set_tests_properties(Hello
        PROPERTIES PASS_REGULAR_EXPRESSION "Hello, World!")
