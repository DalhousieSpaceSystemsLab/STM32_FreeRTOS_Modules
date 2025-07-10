cmake_minimum_required(VERSION 3.16)

project(CoreSoftwareLibrary CXX)

file(MAKE_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(NANOPB_SRC_ROOT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/Lib/Nanopb)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/Lib/Nanopb/extra")

find_package(Nanopb REQUIRED)

# Generate nanopb files (this replaces the custom command)
nanopb_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILE})

# Define the library using the explicitly defined generated files
add_library(CoreSoftwareLibrary
    # Your existing source files
    Src/task_communication.cpp
    Src/setup.cpp
    # Generated nanopb files
    ${PROTO_SRCS}
    ${PROTO_HDRS}
)

# Include the interface headers
target_include_directories(CoreSoftwareLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)

target_link_libraries(CoreSoftwareLibrary PUBLIC 
    nanopb
    stm32cubemx
)
