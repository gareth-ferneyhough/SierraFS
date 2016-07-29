set (CMAKE_CXX_STANDARD 11)
add_executable (simple simple.cc)
include_directories ("${PROJECT_SOURCE_DIR}/src")
target_link_libraries (simple fuse++)
file (COPY postbuild.py DESTINATION bin)
#add_custom_target (run
#    COMMAND python "${PROJECT_BINARY_DIR}/bin/postbuild.py"
#    )
