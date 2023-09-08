cmake_minimum_required(VERSION 3.15)

project(moonlander VERSION 0.3 LANGUAGES CXX)
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

if(NOT XLIBS_ROOT_FOLDER)
	set(XLIBS_ROOT_FOLDER ${CMAKE_SOURCE_DIR}/..)
endif()
add_subdirectory(${XLIBS_ROOT_FOLDER}/tiled tiled_build)

find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)
add_custom_command(
		OUTPUT resources.cpp
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		COMMAND ${GLIB_COMPILE_RESOURCES}
		ARGS --target=${CMAKE_CURRENT_BINARY_DIR}/resources.cpp --generate-source resources.xml
		VERBATIM
		MAIN_DEPENDENCY resources.xml
		DEPENDS
		${CMAKE_SOURCE_DIR}/res/landscape.csv
		${CMAKE_SOURCE_DIR}/res/platform.csv
		${CMAKE_SOURCE_DIR}/res/rocket.csv
)

add_custom_target(
		moonlander-resources
		DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/resources.cpp
)

add_executable(moonlander main.cpp
				MainWnd.cpp MainWnd.h
				MoonLander.cpp MoonLander.h
				ISerializable.h
				GameObject.cpp GameObject.h
				${CMAKE_CURRENT_BINARY_DIR}/resources.cpp IReader.h InputStreamReader.cpp InputStreamReader.h)
set_target_properties(moonlander PROPERTIES C_STANDARD 14 C_STANDARD_REQUIRED ON)
set_source_files_properties(
		${CMAKE_CURRENT_BINARY_DIR}/resources.cpp
		PROPERTIES GENERATED TRUE
)
add_dependencies(${PROJECT_NAME} moonlander-resources)

target_include_directories(moonlander PRIVATE ${XLIBS_ROOT_FOLDER})
include_directories(${GTKMM3_INCLUDE_DIRS})
target_link_libraries(moonlander tiled ${GTKMM3_LIBRARIES})
add_definitions(${GTKMM3_CFLAGS_OTHER})