cmake_minimum_required(VERSION 3.10)

project(raytracer)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-gnu-unique")

add_compile_options(-O3 -march=native -ffast-math -flto)

file(GLOB SRC_SHARED "src/shared/*.cpp")
file(GLOB SRC_MAIN "src/main/*.cpp")

add_executable(raytracer src/Main.cpp ${SRC_SHARED} ${SRC_MAIN})

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBCONFIG REQUIRED libconfig++)
target_link_libraries(raytracer ${LIBCONFIG_LIBRARIES})
target_include_directories(raytracer PUBLIC ${LIBCONFIG_INCLUDE_DIRS})

target_link_libraries(raytracer dl)

target_include_directories(raytracer PUBLIC src/shared)
target_include_directories(raytracer PUBLIC src/main)

set_target_properties(raytracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${PROJECT_SOURCE_DIR}/plugins)

add_subdirectory(src/primitives/sphere)
add_subdirectory(src/primitives/plane)
add_subdirectory(src/primitives/cylinder)
add_subdirectory(src/materials/flat_color)
add_subdirectory(src/lights/directional_light)
add_subdirectory(src/lights/ambient_light)
add_subdirectory(src/lights/point_light)
