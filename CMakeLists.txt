cmake_minimum_required(VERSION 3.10)

project(raytracer)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-gnu-unique")

file(GLOB SRC_SHARED "src/shared/*.cpp")

add_executable(raytracer src/Main.cpp ${SRC_SHARED})

target_include_directories(raytracer PUBLIC src/shared)

set_target_properties(raytracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_subdirectory(src/primitives/sphere)
add_subdirectory(src/lights/directional_light)
add_subdirectory(src/lights/ambient_light)
