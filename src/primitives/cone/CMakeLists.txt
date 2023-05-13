file(GLOB SRC_CONE *.cpp)

add_library(raytracer_cone SHARED ${SRC_CONE} ${SRC_SHARED})

target_include_directories(raytracer_cone PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/)

set_target_properties(raytracer_cone PROPERTIES PREFIX "")

set_target_properties(raytracer_cone PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins)

target_link_libraries(raytracer_cone)
