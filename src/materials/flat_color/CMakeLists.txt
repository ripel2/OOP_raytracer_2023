file(GLOB SRC_FLAT_COLOR *.cpp)

add_library(raytracer_flat_color SHARED ${SRC_FLAT_COLOR} ${SRC_SHARED})

target_include_directories(raytracer_flat_color PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/)

set_target_properties(raytracer_flat_color PROPERTIES PREFIX "")

set_target_properties(raytracer_flat_color PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins)

target_link_libraries(raytracer_flat_color)
