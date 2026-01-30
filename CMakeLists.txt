cmake_minimum_required(VERSION 3.10)

project(ExampleProject)

set(CMAKE_CXX_STANDARD 14)

# Find Clang and LLVM
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})

add_definitions(${LLVM_DEFINITIONS})

# Include source files
set(SOURCES
    main.cpp
    # Add more source files here
)

add_executable(ExampleProject ${SOURCES})

# Link libraries
llvm_map_components_to_libnames(llvm_libs core)
target_link_libraries(ExampleProject ${llvm_libs})