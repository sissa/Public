# CMake demo for Fortran with C
cmake_minimum_required(VERSION 3.16)
project(project VERSION 1.0 LANGUAGES Fortran)

add_executable(hello hello.f90)
enable_language(C)
add_executable(ftesthash inthash.c hashfunc.f90 ftesthash.f90)
add_executable(ctesthash inthash.c ctesthash.c)

enable_testing()
add_test(NAME Hello
  COMMAND sh -c "exec $<TARGET_FILE:hello>")
set_tests_properties(Hello
        PROPERTIES PASS_REGULAR_EXPRESSION "Hello, World!")
