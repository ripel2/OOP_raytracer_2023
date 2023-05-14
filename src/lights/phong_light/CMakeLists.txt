file(GLOB SRC_PHONG_LIGHT *.cpp)

add_library(raytracer_point_light SHARED ${SRC_PHONG_LIGHT} ${SRC_SHARED})

target_include_directories(raytracer_point_light PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/)

set_target_properties(raytracer_point_light PROPERTIES PREFIX "")

set_target_properties(raytracer_point_light PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins)

target_link_libraries(raytracer_point_light)
