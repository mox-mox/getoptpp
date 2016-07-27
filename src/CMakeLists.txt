# Notice name prefix of this variable, set by CMake according
# to value given with "project()" in the root CMakeLists.txt.
include_directories(${i3ipc-doodle_SOURCE_DIR}/libs/getoptpp/getoptpp)
add_library(getoptpp getopt_pp.cpp)
