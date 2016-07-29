cmake_minimum_required (VERSION 2.6)
project (SierraFS)
set (SierraFS_VERSION_MAJOR 0)
set (SierraFS_VERSION_MINOR 0)

configure_file (
    "${PROJECT_SOURCE_DIR}/sierrafs-config.h.in"
    "${PROJECT_BINARY_DIR}/sierrafs-config.h"
    )

#install (FILES "${PROJECT_BINARY_DIR}/sierrafs-config.h"
#         DESTINATION include)

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
add_subdirectory(examples)
