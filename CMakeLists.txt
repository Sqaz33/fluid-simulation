cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(fluid_simulation LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "C:/SFML-3.0.0")
find_package(SFML 3 REQUIRED COMPONENTS Graphics)

file(GLOB_RECURSE SRC "src/*.cpp" "src/*.c")
file(GLOB_RECURSE INCLUDE "inlcue/*.hpp" "src/*.h")

add_executable(main ${SRC} ${INCLUDE})

target_link_libraries(main PRIVATE SFML::Graphics)
