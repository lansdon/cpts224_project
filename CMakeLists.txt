cmake_minimum_required (VERSION 2.6)
project (cs224_project)
# The version number.
set (cs224_project_VERSION_MAJOR 1)
set (cs224_project_VERSION_MINOR 0)

#configure a header file to pass some of the CMake settings
#to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/project_config.h.in"
	"${PROJECT_BINARY_DIR}/project_config.h"
)

# add the binary tree to the search path for include files
# so that we will find project_config.h
include_directories("${PROJECT_BINARY_DIR}")

#include_directories ("${PROJECT_SOURCE_DIR}/cma")
#add_subdirectory (cma)

# add CMA Library
add_library (cma cma.c)

# add the executable
add_executable(ma ma.c)
target_link_libraries (ma cma)


# add the install targets
#install (TARGETS cs224_project DESTINATION bin)
#install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)


