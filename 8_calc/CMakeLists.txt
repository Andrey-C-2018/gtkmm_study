cmake_minimum_required(VERSION 3.15)

project(calc VERSION 0.7 LANGUAGES CXX)
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

pkg_check_modules(GMP REQUIRED gmp)
if(NOT ${GMP_FOUND})
	message(FATAL_ERROR "the gmp library is not found on the system")
	return()
endif()
message(STATUS "gmp library added")

#######################################

find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)
add_custom_command(
        OUTPUT resources.cpp
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${GLIB_COMPILE_RESOURCES}
        ARGS --target=${CMAKE_CURRENT_BINARY_DIR}/resources.cpp --generate-source resources.xml
        VERBATIM
        MAIN_DEPENDENCY resources.xml
        DEPENDS
        ${CMAKE_SOURCE_DIR}/res/window.glade
)

add_custom_target(
		calc-resource
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/resources.cpp
)

add_executable(calc main.cpp
		CalcWnd.cpp CalcWnd.h
		Interactor.cpp Interactor.h
		IOperation.h
		Calc.cpp Calc.h
		OperationsFactory.cpp OperationsFactory.h
		BasicOperations.h BasicOperations.cpp
        ${CMAKE_CURRENT_BINARY_DIR}/resources.cpp)

set_target_properties(calc PROPERTIES C_STANDARD 14 C_STANDARD_REQUIRED ON)
set_source_files_properties(
        ${CMAKE_CURRENT_BINARY_DIR}/resources.cpp
        PROPERTIES GENERATED TRUE
)
add_dependencies(${PROJECT_NAME} calc-resource)

include_directories(${GTKMM3_INCLUDE_DIRS})
include_directories(${GMP_INCLUDE_DIRS})
target_link_libraries(calc ${GTKMM3_LIBRARIES} ${GMP_LIBRARIES} gmpxx)
add_definitions(${GTKMM3_CFLAGS_OTHER})
