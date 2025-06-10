cmake_minimum_required(VERSION 3.16)

project(CoreSoftwareLibrary CXX)

# Define the library
add_library(CoreSoftwareLibrary
    Src/pin_communication.cpp
)

# Include the interface headers
target_include_directories(CoreSoftwareLibrary
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Inc
        # Replace the following with the actual path to STM32CubeMX-generated includes
        ${CMAKE_CURRENT_SOURCE_DIR}/../Core/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../Drivers/STM32F4xx_HAL_Driver/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../Drivers/CMSIS/Device/ST/STM32F4xx/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/../Drivers/CMSIS/Include
        # FreeRTOS includes (adjust paths as needed)
        ${CMAKE_CURRENT_SOURCE_DIR}/../Middlewares/Third_Party/FreeRTOS/Source/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F
)

# Optionally define a compile definition if needed
target_compile_definitions(CoreSoftwareLibrary
    PUBLIC
        STM32F466RE  # Adjust this based on your MCU
)
