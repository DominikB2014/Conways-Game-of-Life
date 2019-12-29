cmake_minimum_required(VERSION 3.6)   # CMake version check
project(A4)               # Create project "A4
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard

include_directories(../include)
include_directories(../experiment)
include_directories(../catch)

set(SOURCE_FILES GameBoard.cpp View.cpp)            # Add main.cpp file of project root directory as source file
set(TEST_FILES ../test/testView.cpp ../test/testBoard.cpp)            # Add main.cpp file of project root directory as source file

add_executable(experiment ../experiment/main.cpp ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable
add_executable(test ../test/testmain.cpp ${TEST_FILES})       # Add executable target with source files listed in SOURCE_FILES variable