file(GLOB SRC_raytracer_directional_light *.cpp)

add_library(raytracer_directional_light SHARED ${SRC_raytracer_directional_light} ${SRC_SHARED})

target_include_directories(raytracer_directional_light PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/)

set_target_properties(raytracer_directional_light PROPERTIES PREFIX "")

set_target_properties(raytracer_directional_light PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins)

target_link_libraries(raytracer_directional_light)
