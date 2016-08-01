set (CMAKE_CXX_STANDARD 11)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
add_executable (simple simple.cc)
include_directories ("${PROJECT_SOURCE_DIR}/src")
target_link_libraries (simple fuse++)
file (COPY postbuild.py DESTINATION bin)
add_custom_target (run
    COMMAND python "${PROJECT_BINARY_DIR}/examples/bin/postbuild.py"
    )
