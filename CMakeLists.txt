cmake_minimum_required(VERSION 3.10)

project(raytracer)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-gnu-unique")

add_executable(raytracer src/Main.cpp)

target_include_directories(raytracer PRIVATE ${PROJECT_SOURCE_DIR}/src/shared)
target_include_directories(raytracer PRIVATE ${PROJECT_SOURCE_DIR}/src/primitives/sphere)
target_include_directories(raytracer PRIVATE ${PROJECT_SOURCE_DIR}/src/primitives/plane)
target_include_directories(raytracer PRIVATE ${PROJECT_SOURCE_DIR}/src/lights/ambient_light)
target_include_directories(raytracer PRIVATE ${PROJECT_SOURCE_DIR}/src/lights/directional_light)
target_include_directories(raytracer PRIVATE ${PROJECT_SOURCE_DIR}/src/materials/flat_color)

file(GLOB_RECURSE SOURCES "src/shared/*.cpp" "src/primitives/sphere/*.cpp" "src/primitives/plane/*.cpp" "src/lights/ambient_light/*.cpp" "src/lights/directional_light/*.cpp" "src/materials/flat_color/*.cpp")
target_sources(raytracer PRIVATE ${SOURCES})

set_target_properties(raytracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})