cmake_minimum_required(VERSION 3.15)

project(tiled VERSION 0.4 LANGUAGES CXX)
if(NOT CMAKE_BUILD_TYPE)
       set(CMAKE_BUILD_TYPE Release)
endif()

if(NOT XLIBS_ROOT_FOLDER)
	set(XLIBS_ROOT_FOLDER ${CMAKE_SOURCE_DIR}/..)
endif()

if(NOT XLIBS_OUTPUT_FOLDER)
	if(MSVC_TOOLSET_VERSION GREATER 80)
		set(XLIBS_OUTPUT_FOLDER ${XLIBS_ROOT_FOLDER}/0libs)
	else()
		set(XLIBS_OUTPUT_FOLDER ${XLIBS_ROOT_FOLDER}/0libs/${CMAKE_BUILD_TYPE})
	endif()
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${XLIBS_OUTPUT_FOLDER})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${XLIBS_OUTPUT_FOLDER})

#######################################

find_package(PkgConfig REQUIRED)
if(NOT PKG_CONFIG_FOUND)
	message(FATAL_ERROR "no Pkg-Config on the system")
	return()
endif()

pkg_check_modules(GTKMM3 REQUIRED gtkmm-3.0)
if(NOT ${GTKMM3_FOUND})
	message(FATAL_ERROR "the gtkmm library v3.0 is not found on the system")
	return()
endif()
message(STATUS "gtkmm include path: ${GTKMM3_INCLUDE_DIRS}")

#######################################

add_library(tiled GameMainWnd.cpp GameMainWnd.h
		GameField.cpp GameField.h
		GameScreen.cpp GameScreen.h
        IGameScreen.h
		IEventsHandler.h
		IDrawable.h
		Color.h Color.cpp)
set_target_properties(tiled PROPERTIES C_STANDARD 14 C_STANDARD_REQUIRED ON)
target_include_directories(tiled PUBLIC ${GTKMM3_INCLUDE_DIRS})