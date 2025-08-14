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

# Add mp-units
include(FetchContent)
FetchContent_Declare(
    mp-units
    GIT_REPOSITORY https://github.com/mpusz/mp-units
    GIT_TAG d9dce46c21f6d915424112fd8b5e2163addc051b
    SOURCE_SUBDIR src
)
set(MP_UNITS_BUILD_CXX_MODULES OFF)
set(MP_UNITS_API_STD_FORMAT ON)
FetchContent_MakeAvailable(mp-units)

# Compile library
add_library(mpy-units SHARED src/mpy-units/test_module.cpp)
target_sources(mpy-units PRIVATE FILE_SET HEADERS
  FILES ${PROJECT_SOURCE_DIR}/src/mpy-units/test_module.hpp)
target_link_libraries(mpy-units PUBLIC mp-units::mp-units)
