set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_subdirectory (${PROJECT_SOURCE_DIR}/dependencies/googletest-release-1.7.0 ${CMAKE_CURRENT_BINARY_DIR}/dependencies)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
file (GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
add_executable (runUnitTests ${TEST_FILES})

# Link test executable against gtest & gtest_main
target_link_libraries (runUnitTests gtest gtest_main)
add_test (runUnitTests ${CMAKE_CURRENT_BINARY_DIR}/runUnitTests --gtest_color=yes)

# Integration tests
file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/example_simple_test.py DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_custom_target (test-integration
    COMMAND py.test "${PROJECT_BINARY_DIR}/test/example_simple_test.py"
    )
