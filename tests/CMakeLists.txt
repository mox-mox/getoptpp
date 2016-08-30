# Build script for the test program
cmake_minimum_required(VERSION 3.0)
project(getopt)

#{{{Variables: SRCS INCDIRS LINKDIRS LIBS CMAKE_MODULE_PATH

file(GLOB SRCS cmake_test.cpp)
set(INCDIRS "${CMAKE_CURRENT_SOURCE_DIR}")
set(INCDIRS_SYS "")
set(LIBS "")
#}}}


add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/.." "${CMAKE_CURRENT_BINARY_DIR}/getopt_pp")




#{{{CXXFLAGS

# Set build type when generating the Makefile like: cmake -DCMAKE_BUILD_TYPE=Debug ..
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS}         -std=c++11 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Os")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   -std=c++11 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -O0 -ggdb -DDEBUG -save-temps")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Os -DNDEBUG")
#}}}


add_executable(getopt_pp_test ${SRCS})
target_link_libraries(getopt_pp_test ${LIBS} )
target_include_directories(getopt_pp_test PUBLIC ${INCDIRS})
target_include_directories(getopt_pp_test SYSTEM PUBLIC ${INCDIRS_SYS})
