cmake_minimum_required (VERSION 2.6)
project (SierraFS)
set (SierraFS_VERSION_MAJOR 0)
set (SierraFS_VERSION_MINOR 0)

configure_file (
    "${PROJECT_SOURCE_DIR}/sierrafs-config.h.in"
    "${PROJECT_BINARY_DIR}/sierrafs-config.h"
    )

include_directories ("${PROJECT_BINARY_DIR}")

add_executable (sierrafs sierrafs.cc)	
target_link_libraries (sierrafs ${EXTRA_LIBS})

install (TARGETS sierrafs DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/sierrafs-config.h"
         DESTINATION include)
