cmake_minimum_required(VERSION 3.6)
project(ticTacToe)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES  Fighterplane.cpp Fighterplane.h main.cpp FighterplaneTest.cpp Designbycontract.h)

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES Fighterplane.cpp Fighterplane.h FighterplaneTest.cpp )

# Create RELEASE target
add_executable(ttt ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(ttt_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(ttt_debug gtest)