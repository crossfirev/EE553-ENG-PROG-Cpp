cmake_minimum_required(VERSION 3.23)

# Project name = folder name (hw01, hw02, …)
get_filename_component(TARGET_NAME "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
project(${TARGET_NAME} LANGUAGES CXX)

# Language standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set a default build type (Debug if none given)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

# Grab all cpp files in src/
file(GLOB SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
if(NOT SOURCES)
  message(FATAL_ERROR "No sources found in ${CMAKE_CURRENT_SOURCE_DIR}/src")
endif()

# Executable
add_executable(${TARGET_NAME} ${SOURCES})

# Includes
target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Warnings
if(MSVC)
  target_compile_options(${TARGET_NAME} PRIVATE /W4 /permissive-)
else()
  target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Put binary directly in the build dir
set_target_properties(${TARGET_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# Summary
message(STATUS "========== ${PROJECT_NAME} ==========")
message(STATUS " CMAKE_BUILD_TYPE:   ${CMAKE_BUILD_TYPE}")
message(STATUS " CXX Compiler:       ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " CXX Standard:       ${CMAKE_CXX_STANDARD}")
message(STATUS " Sources:            ${SOURCES}")
message(STATUS "====================================")
