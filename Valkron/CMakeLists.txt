cmake_minimum_required(VERSION 3.31 FATAL_ERROR)
project(Valkron VERSION 0.0.1)

# C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type (Debug, Release, RelWithDebInfo, MinSizeRel)" FORCE)
endif()

# Compiler flags
if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /W4 /MDd /Zi /Od")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /W3 /MD /O2")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -Wpedantic")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG") 
endif()

# Add external dependencies
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glfw)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Source and header files
file(GLOB PROJECT_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Valkron/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Valkron/Events/*.hpp
)
file(GLOB PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Valkron/*.cpp
)

# Create the Valkron library
add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_precompile_headers(${PROJECT_NAME} PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/src/valkron_pch.hpp
)

# Link spdlog to Valkron
target_link_libraries(${PROJECT_NAME}
spdlog::spdlog
glfw
)

# Define macros for the library
if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC VALKRON_PLATFORM_WINDOWS VALKRON_BUILD_DLL)
endif()

# Set output directories
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/src"
)