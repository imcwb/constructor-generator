# Clang Library Configuration

cmake_minimum_required(VERSION 3.0)

project(ConstructorGenerator)

# Find Clang library
find_package(Clang REQUIRED)

# Include directories
include_directories(${CLANG_INCLUDE_DIRS})

# Link Clang libraries
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CLANG_LIBRARIES}")

add_executable(ConstructorGenerator main.cpp)    
