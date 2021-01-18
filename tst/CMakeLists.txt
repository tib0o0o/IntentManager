
cmake_minimum_required(VERSION 3.13)
project(IntentManagerUT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
SET( CMAKE_BUILD_TYPE Debug )
SET(CMAKE_CXX_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C++ compiler during coverage builds."
    FORCE )
SET(CMAKE_C_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C compiler during coverage builds."
    FORCE )
SET(CMAKE_EXE_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used for linking binaries during coverage builds."
    FORCE )
SET(CMAKE_SHARED_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used by the shared libraries linker during coverage builds."
    FORCE )
################################
# GTest
################################
enable_testing()
include_directories (./inc ./../theardparty/googletest/include/ ./../inc/IntentManager/)

################################
# Unit Tests
################################
add_test(IntentManagerUT IntentManagerUT)


add_executable(IntentManagerUT ./src/main.cpp ./src/IntentManagerUT.cpp ./src/IntentItemUT.cpp
                ./../src/IntentManager/IntentManager.cpp ./../src/IntentManager/IntentItem.cpp)


target_link_libraries(IntentManagerUT gtest gtest_main pthread)
