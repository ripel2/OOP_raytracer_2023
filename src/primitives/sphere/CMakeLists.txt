file(GLOB SRC_SPHERE *.cpp)

add_library(raytracer_sphere SHARED ${SRC_SPHERE} ${SRC_SHARED})

target_include_directories(raytracer_sphere PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/)

set_target_properties(raytracer_sphere PROPERTIES PREFIX "")

set_target_properties(raytracer_sphere PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins)

target_link_libraries(raytracer_sphere)
