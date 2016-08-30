set(INCDIRS ${INCDIRS} "${CMAKE_CURRENT_SOURCE_DIR}/getoptpp" PARENT_SCOPE)
set(LIBS ${LIBS} getoptpp PARENT_SCOPE)

add_library(getoptpp STATIC "${CMAKE_CURRENT_SOURCE_DIR}/src/getopt_pp.cpp")
target_include_directories(getoptpp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/getoptpp")
