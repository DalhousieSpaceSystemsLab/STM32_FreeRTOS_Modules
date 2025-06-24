cmake_minimum_required(VERSION 3.16)

project(CoreSoftwareLibrary CXX)

# Define the library
add_library(CoreSoftwareLibrary
    # Src/pin_communication.cpp
    Src/task_communication.cpp
    Src/setup.cpp
)

# Include the interface headers
target_include_directories(CoreSoftwareLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)

target_link_libraries(CoreSoftwareLibrary PUBLIC stm32cubemx)
