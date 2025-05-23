# Find all module directories inside Modules/
file(GLOB MODULE_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)

foreach(MODULE ${MODULE_DIRS})
    set(MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE}")
    set(MODULE_SRC_DIR "${MODULE_PATH}/Src")
    set(MODULE_INC_DIR "${MODULE_PATH}/Inc")

    if(IS_DIRECTORY "${MODULE_SRC_DIR}")
        # Add all .c and .cpp files from Src
        file(GLOB_RECURSE MODULE_SOURCES "${MODULE_SRC_DIR}/*.c" "${MODULE_SRC_DIR}/*.cpp")
        target_sources(${PROJECT_NAME} PRIVATE ${MODULE_SOURCES})
    endif()

    if(IS_DIRECTORY "${MODULE_INC_DIR}")
        # Add Inc/ as an include directory
        target_include_directories(${PROJECT_NAME} PRIVATE "${MODULE_INC_DIR}")
    endif()
endforeach()
