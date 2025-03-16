cmake_minimum_required(VERSION 3.10)
project(MGBAController C)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Include directories
include_directories(include)

# Library source files
set(LIB_SOURCES
    src/mgba_connection.c
    src/mgba_controller.c
    src/mgba_map.c
)

# Create shared library
add_library(mgba_controller SHARED ${LIB_SOURCES})
target_link_libraries(mgba_controller ws2_32)

# Create static library
add_library(mgba_controller_static STATIC ${LIB_SOURCES})
set_target_properties(mgba_controller_static PROPERTIES OUTPUT_NAME mgba_controller)
target_link_libraries(mgba_controller_static ws2_32)

# Example executables
add_executable(simple_controller examples/simple_controller.c)
target_link_libraries(simple_controller mgba_controller_static)

add_executable(map_viewer examples/map_viewer.c)
target_link_libraries(map_viewer mgba_controller_static)

# Install rules
install(TARGETS mgba_controller mgba_controller_static
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/mgba_controller)