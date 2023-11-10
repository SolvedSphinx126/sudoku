cmake_minimum_required(VERSION 3.12)
project(SudokuSolver)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the build type to Debug by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Add source files
set(SOURCE_FILES
    cell.cpp
    grid.cpp
    main.cpp
)

# Add header files
set(HEADER_FILES
    cell.h
    grid.h
)

# Add the executable
add_executable(SudokuSolver ${SOURCE_FILES} ${HEADER_FILES})