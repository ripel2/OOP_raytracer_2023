file(GLOB SRC_AMBIENT_LIGHT *.cpp)

add_library(ambiant_light SHARED ${SRC_AMBIENT_LIGHT} ${SRC_SHARED})

target_include_directories(ambiant_light PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/)

set_target_properties(ambiant_light PROPERTIES PREFIX "")

set_target_properties(ambiant_light PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins)

target_link_libraries(ambiant_light)
