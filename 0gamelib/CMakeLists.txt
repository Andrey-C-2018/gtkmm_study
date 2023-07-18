cmake_minimum_required(VERSION 3.15)

project(gamelib VERSION 0.1 LANGUAGES CXX)
if(NOT CMAKE_BUILD_TYPE)
       set(CMAKE_BUILD_TYPE Release)
endif()

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

if(NOT MSVC OR MSVC_TOOLSET_VERSION LESS_EQUAL 80)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/${CMAKE_BUILD_TYPE})
endif()

add_library(gamelib GameField.cpp GameField.h)
set_target_properties(gamelib PROPERTIES C_STANDARD 14 C_STANDARD_REQUIRED ON)
target_include_directories(gamelib PUBLIC ${GTKMM3_INCLUDE_DIRS})