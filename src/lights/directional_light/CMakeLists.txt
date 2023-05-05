file(GLOB SRC_DIRECTIONAL_LIGHT *.cpp)

add_library(directional_light SHARED ${SRC_DIRECTIONAL_LIGHT} ${SRC_SHARED})

target_include_directories(directional_light PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/)

set_target_properties(directional_light PROPERTIES PREFIX "")

set_target_properties(directional_light PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins)

target_link_libraries(directional_light)
