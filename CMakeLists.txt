cmake_minimum_required(VERSION 3.15)
project(c_engine C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(external/raylib)

file(GLOB_RECURSE ENGINE_SRC
    src/engine/*.c
    src/object/*.c
    src/scene/*.c
    src/graphics/*c
)

add_executable(game
    game/main.c
    ${ENGINE_SRC}
)

target_include_directories(game PRIVATE src)

target_link_libraries(game raylib)
