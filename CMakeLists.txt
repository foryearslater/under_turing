cmake_minimum_required(VERSION 3.10)

project(UNDER_TURING)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

set(EXECUTABLE_SOURCE_FILES turing/main.cpp)

add_executable(${PROJECT_NAME} ${EXECUTABLE_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} UNDER_TURING)

target_include_directories(${PROJECT_NAME} PUBLIC include)

set(EASYX_LIB_PATH "D:/Software/visual_studio/VC/Auxiliary/VS/lib/x64/EasyXa.lib")
target_link_libraries(${PROJECT_NAME} ${EASYX_LIB_PATH})
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)