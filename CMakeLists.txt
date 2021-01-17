
cmake_minimum_required(VERSION 3.13)
project(IntentTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")




add_executable(IntentTest ./src/main.cpp ./src/IntentManager/IntentManager.cpp ./src/IntentManager/IntentItem.cpp)


include_directories (./inc/IntentManager)
