cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(getoptpp)

set(GETOPTPP_INCLUDE_DIRS
	${CMAKE_CURRENT_SOURCE_DIR}/getoptpp
)

set(GETOPTPP_LIBRARY_DIRS
	${PROJECT_BINARY_DIR}
)

file(GLOB_RECURSE SRC src/*.cpp)
add_library(getoptpp ${SRC})

target_include_directories(getoptpp
	PUBLIC
		${GETOPTPP_INCLUDE_DIRS}
)

link_directories(getoptpp
	PUBLIC
		${GETOPTPP_LIBRARY_DIRS}
)
target_link_libraries(getoptpp
	PUBLIC
	${GETOPT_LIBRARIES}
)

target_compile_options(getoptpp
	PRIVATE -std=c++11 -Wall -Wextra -Wno-unused-parameter
)

if (CMAKE_BUILD_TYPE STREQUAL "DEBUG")
	target_compile_options(getoptpp
		PUBLIC -g3
	)
elseif (CMAKE_BUILD_TYPE EQUAL "RELEASE")
	target_compile_options(getoptpp
		PUBLIC -O2
	)
endif()


set(GETOPTPP_LIBRARY_DIRS "${GETOPTPP_LIBRARY_DIRS} ${PROJECT_BINARY_DIR}")
set(GETOPTPP_LIBRARIES "${GETOPTPP_LIBRARIES};getoptpp")

get_directory_property(HAS_PARENT_DIRECTORY PARENT_DIRECTORY)
if(HAS_PARENT_DIRECTORY)
	set(GETOPTPP_LIBRARY_DIRS ${GETOPTPP_LIBRARY_DIRS} PARENT_SCOPE)
	set(GETOPTPP_INCLUDE_DIRS ${GETOPTPP_INCLUDE_DIRS} PARENT_SCOPE)
	set(GETOPTPP_LIBRARIES ${GETOPTPP_LIBRARIES} PARENT_SCOPE)
endif()
