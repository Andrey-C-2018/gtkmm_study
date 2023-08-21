cmake_minimum_required(VERSION 3.15)

project(triangles VERSION 1.0 LANGUAGES CXX)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(src src_build)
add_subdirectory(tests tests_build)

find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)
add_custom_command(
        OUTPUT resources.cpp
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${GLIB_COMPILE_RESOURCES}
        ARGS --target=${CMAKE_CURRENT_BINARY_DIR}/resources.cpp --generate-source resources.xml
        VERBATIM
        MAIN_DEPENDENCY resources.xml
        DEPENDS
        ${CMAKE_SOURCE_DIR}/res/left.svg
		${CMAKE_SOURCE_DIR}/res/blank.svg
		${CMAKE_SOURCE_DIR}/res/right.svg
)

add_custom_target(
        triangles-res
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/resources.cpp
)

add_executable(triangles main.cpp
       	    ${CMAKE_CURRENT_BINARY_DIR}/resources.cpp)

set_target_properties(triangles PROPERTIES C_STANDARD 14 C_STANDARD_REQUIRED ON)
set_source_files_properties(
        ${CMAKE_CURRENT_BINARY_DIR}/resources.cpp
        PROPERTIES GENERATED TRUE
)
add_dependencies(${PROJECT_NAME} triangles_lib triangles-res)

include_directories(${GTKMM3_INCLUDE_DIRS})
target_link_libraries(triangles triangles_lib ${GTKMM3_LIBRARIES})
add_definitions(${GTKMM3_CFLAGS_OTHER})
