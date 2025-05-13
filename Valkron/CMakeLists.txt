cmake_minimum_required(VERSION 3.31 FATAL_ERROR)
project(Valkron VERSION 0.0.1)


# Cmake C++ standard
set(CMAKE_CXX_STANDARD 23) # Use C++23
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disable compiler-specific extensions


# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type (Debug, Release, RelWithDebInfo, MinSizeRel)" FORCE)
endif()


# Set compiler flags
if(MSVC)
    # MSVC specific flags
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /W4 /MDd /Zi /Od") # Debug flags
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /W3 /MD /O2")  # Release flags
else()
    # GCC/Clang-specific flags
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -Wpedantic") # Debug flags
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")                # Release flags
endif()


# include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Valkron
)

# add source, header and resource files
file(GLOB PROJECT_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Valkron/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Valkron/*.hpp
)
file(GLOB PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Valkron/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Valkron/*.c
)

source_group("include" FILES ${PROJECT_HEADERS})
source_group("src" FILES ${PROJECT_SOURCES})

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES} ${PROJECT_HEADERS})

# Set the output directory for the library
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/src"
)