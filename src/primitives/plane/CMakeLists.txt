file(GLOB SRC_PLANE *.cpp)

add_library(raytracer_plane SHARED ${SRC_PLANE} ${SRC_SHARED})

target_include_directories(raytracer_plane PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/)

set_target_properties(raytracer_plane PROPERTIES PREFIX "")

set_target_properties(raytracer_plane PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins)

target_link_libraries(raytracer_plane)
