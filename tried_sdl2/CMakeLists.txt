cmake_minimum_required(VERSION 3.6)
cmake_policy(SET CMP0076 NEW)
project(pract_cm LANGUAGES C)
add_subdirectory(mylib)
set (SRC example_sdl.c)

find_package(SDL2 CONFIG REQUIRED )

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PUBLIC ${SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(${PROJECT_NAME} PUBLIC mylib)
install(TARGETS ${PROJECT_NAME})
