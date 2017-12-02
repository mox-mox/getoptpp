set(INCDIRS ${INCDIRS} "${CMAKE_CURRENT_SOURCE_DIR}/getoptpp" PARENT_SCOPE)
set(LIBS ${LIBS} "${CMAKE_CURRENT_BINARY_DIR}/libgetoptpp.a" PARENT_SCOPE)


if(NOT ADDED_GETOPTPP_LIBRARY_YET)
	add_library(getoptpp STATIC "${CMAKE_CURRENT_SOURCE_DIR}/src/getopt_pp.cpp")
	target_include_directories(getoptpp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/getoptpp")
	target_compile_options(    getoptpp PUBLIC -std=c++17 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors)
	set(ADDED_GETOPTPP_LIBRARY_YET TRUE CACHE BOOL "Only add the library target once, even if multiple projects require it." FORCE)
endif()




