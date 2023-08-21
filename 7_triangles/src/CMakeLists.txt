cmake_minimum_required(VERSION 3.15)

project(triangles_lib VERSION 1.0 LANGUAGES CXX)
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

add_library(triangles_lib ViewController.cpp ViewController.h
        Interactor.cpp Interactor.h
        IView.h
			Solver.cpp Solver.h
			Field.cpp Field.h Move.h)

set_target_properties(triangles_lib PROPERTIES C_STANDARD 14 C_STANDARD_REQUIRED ON)

include_directories(${GTKMM3_INCLUDE_DIRS})
add_definitions(${GTKMM3_CFLAGS_OTHER})
