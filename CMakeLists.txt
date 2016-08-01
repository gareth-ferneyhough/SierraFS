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

################################
# GTest
################################
ADD_SUBDIRECTORY (dependencies/googletest-release-1.7.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
set (TEST_DIR ${CMAKE_SOURCE_DIR}/test/)
file (GLOB TEST_FILES ${TEST_DIR}/*.cc)
add_executable (runUnitTests ${TEST_FILES})

# Link test executable against gtest & gtest_main
target_link_libraries (runUnitTests gtest gtest_main)
add_test (runUnitTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/runUnitTests --gtest_color=yes)
