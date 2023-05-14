file(GLOB SRC_MIRROR *.cpp)

add_library(raytracer_mirror SHARED ${SRC_MIRROR} ${SRC_SHARED})

target_include_directories(raytracer_mirror PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/)

set_target_properties(raytracer_mirror PROPERTIES PREFIX "")

set_target_properties(raytracer_mirror PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins)

target_link_libraries(raytracer_mirror)
