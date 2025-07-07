set(SOURCES
    BGM.cpp
    Draw.cpp
    Final_game.cpp
    If_new_page.cpp
    init_global_variable.cpp
    Key_control.cpp
    List_node_page_data_structure.cpp
    meet.cpp
)
add_library(UNDER_TURING_LIB STATIC ${SOURCES})

target_include_directories(UNDER_TURING_LIB PUBLIC ${CMAKE_SOURCE_DIR}/include)