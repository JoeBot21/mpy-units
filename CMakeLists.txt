cmake_minimum_required(VERSION 3.31.0)
project(import-test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

include(FetchContent)
FetchContent_Declare(
    mp-units
    GIT_REPOSITORY https://github.com/mpusz/mp-units
    GIT_TAG d9dce46c21f6d915424112fd8b5e2163addc051b
    SOURCE_SUBDIR src
)
set(MP_UNITS_BUILD_CXX_MODULES ON)
set(MP_UNITS_API_STD_FORMAT ON)
FetchContent_MakeAvailable(mp-units)

add_library(import-test SHARED src/import-test/main.cpp)
target_link_libraries(import-test PRIVATE mp-units::mp-units)
