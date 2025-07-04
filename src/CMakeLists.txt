set(SOURCES
    BGM.cpp
    Draw.cpp
    Final_game.cpp
    kid.cpp
    loadimage.cpp
    player.cpp
)
add_library(UNDER_TURING_LIB STATIC ${SOURCES})

target_include_directories(UNDER_TURING_LIB PUBLIC ${CMAKE_SOURCE_DIR}/include)