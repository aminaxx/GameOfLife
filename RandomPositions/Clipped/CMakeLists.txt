cmake_minimum_required(VERSION 2.6)
project(GameOfLife)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -lrt -lpthread -lSDL2")

set(SOURCE_FILES
        main.c game.c func.h)

add_executable(GameOfLife ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(GameOfLife ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
