set (CMAKE_CXX_STANDARD 11)
add_executable (simple simple.cc)
target_link_libraries (simple fuse++)

install (TARGETS simple DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/sierrafs-config.h"
         DESTINATION include)

file (COPY postbuild.py DESTINATION bin)
add_custom_target (run
    COMMAND python bin/postbuild.py
    )
