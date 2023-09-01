cmake_minimum_required(VERSION 3.15)

project(moonlander VERSION 0.2 LANGUAGES CXX)
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

if(NOT XLIBS_ROOT_FOLDER)
	set(XLIBS_ROOT_FOLDER ${CMAKE_SOURCE_DIR}/..)
endif()
add_subdirectory(${XLIBS_ROOT_FOLDER}/tiled tiled_build)

add_executable(moonlander main.cpp
				MainWnd.cpp MainWnd.h
				MoonLander.cpp MoonLander.h
				ISerializable.h
				GameObject.cpp GameObject.h)
set_target_properties(moonlander PROPERTIES C_STANDARD 14 C_STANDARD_REQUIRED ON)

target_include_directories(moonlander PRIVATE ${XLIBS_ROOT_FOLDER})
include_directories(${GTKMM3_INCLUDE_DIRS})
target_link_libraries(moonlander tiled ${GTKMM3_LIBRARIES})
add_definitions(${GTKMM3_CFLAGS_OTHER})