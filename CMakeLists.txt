cmake_minimum_required (VERSION 2.6)
project (SierraFS)
set (SierraFS_VERSION_MAJOR 0)
set (SierraFS_VERSION_MINOR 0)

configure_file (
    "${PROJECT_SOURCE_DIR}/sierrafs-config.h.in"
    "${PROJECT_BINARY_DIR}/sierrafs-config.h"
    )

include_directories ("${PROJECT_BINARY_DIR}")
#set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

#find_package (FUSE 3.0 REQUIRED)
#
#if (NOT FUSE_FOUND)
#    message ( FATAL_ERROR "Fuse3 is required")
#endif()
#
#add_definitions(${FUSE_DEFINITIONS})
#include_directories(${FUSE_INCLUDE_DIRS})
#set (EXTRA_LIBS ${EXTRA_LIBS} ${FUSE_LIBRARIES})

set (FUSE_INCLUDE_DIR "/usr/local/include/fuse3")
set (FUSE_LIB_DIR "/usr/local/lib")
set (FUSE_LIBS "fuse3")
include_directories (${FUSE_INCLUDE_DIR})
set (EXTRA_LIBS ${EXTRA_LIBS} ${FUSE_LIBS})

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library (fuse++ fuse++.cc)
add_library (myfuse++ my-fuse++-fs.cc)
add_executable (sierrafs main.cc)	
target_link_libraries (sierrafs fuse++ myfuse++ ${EXTRA_LIBS})
set (CMAKE_CXX_FLAGS "-fpermissive")

install (TARGETS sierrafs DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/sierrafs-config.h"
         DESTINATION include)
