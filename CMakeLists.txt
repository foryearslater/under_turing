cmake_minimum_required(VERSION 3.10)

project(UNDER_TURING)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
add_subdirectory(src)

set(EXECUTABLE_SOURCE_FILES turing/main.cpp)

add_executable(${PROJECT_NAME} ${EXECUTABLE_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}  PUBLIC UNDER_TURING_LIB)

target_include_directories(${PROJECT_NAME} PUBLIC include)


if(DEFINED ENV{EASYX_PATH})
    set(EASYX_SEARCH_PATHS "$ENV{EASYX_PATH}")
else()
    set(EASYX_SEARCH_PATHS
        "$ENV{VCINSTALLDIR}/Auxiliary/VS"
        "$ENV{VSINSTALLDIR}/VC/Auxiliary/VS"
        "$ENV{PROGRAMFILES}/EasyX"
        "C:/Program Files/EasyX"
        "C:/EasyX"
        "D:/Software/visual_studio/VC/Auxiliary/VS" 
    )
endif()

find_library(EASYX_LIB
    NAMES EasyXa EasyX
    PATHS ${EASYX_SEARCH_PATHS}
    PATH_SUFFIXES lib/x64 lib
    DOC "Path to EasyX library"
)

find_path(EASYX_INCLUDE_DIR
    NAMES easyx.h
    PATHS ${EASYX_SEARCH_PATHS}
    PATH_SUFFIXES include
)

if(EASYX_LIB)
    add_library(EasyX STATIC IMPORTED)
    set_target_properties(EasyX PROPERTIES
        IMPORTED_LOCATION ${EASYX_LIB}
    )
    
    if(EASYX_INCLUDE_DIR)
        target_include_directories(EasyX INTERFACE ${EASYX_INCLUDE_DIR})
        message(STATUS "Found EasyX headers: ${EASYX_INCLUDE_DIR}")
    endif()
    
    target_link_libraries(${PROJECT_NAME} PUBLIC EasyX)
    message(STATUS "Linked EasyX from: ${EASYX_LIB}")
else()
    message(FATAL_ERROR "EasyX library not found! "
        "Please install EasyX from https://easyx.cn/ and set EASYX_PATH environment variable.")
endif()

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resource
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/resource
)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)