cmake_minimum_required(VERSION 3.31.0)
project(mpy-units LANGUAGES CXX)

# Force a recent C++ standard for module support
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Disable in-source builds
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed")
endif()

# Compile library
add_library(mpy-units SHARED src/mpy-units/test_module.cpp)
target_sources(mpy-units PRIVATE FILE_SET CXX_MODULES
  FILES ${PROJECT_SOURCE_DIR}/src/mpy-units/test_cpp_module.cpp)
