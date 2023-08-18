cmake_minimum_required(VERSION 3.15)

project(triangles_test VERSION 0.5 LANGUAGES CXX)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

#######################################

find_package(UnitTest++ REQUIRED)
if(NOT UTPP_INCLUDE_DIRS)
	message(FATAL_ERROR "the toolkit UnitTest++ is not found on the system")
	return()
endif()
message(STATUS "UnitTest++ include path: ${UTPP_INCLUDE_DIRS}")

#######################################

add_executable(triangles_test main.cpp SolverTests.cpp FieldTests.cpp)

set_target_properties(triangles_test PROPERTIES C_STANDARD 14 C_STANDARD_REQUIRED ON)
include_directories("../src")
target_include_directories(triangles_test PUBLIC ${UTPP_INCLUDE_DIRS})
target_link_libraries(triangles_test triangles_lib UnitTest++)