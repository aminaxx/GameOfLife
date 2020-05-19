cmake_minimum_required(VERSION 3.11)
cmake_policy(SET CMP0076 NEW)

project(pract_cm LANGUAGES C)

add_subdirectory(mylib)


set (SRC main.c)

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PUBLIC ${SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC mylib) 

install(TARGETS ${PROJECT_NAME})


set(PROJECT_TEST unit_test)
add_executable(${PROJECT_TEST})
target_sources(${PROJECT_TEST} PUBLIC  cunit_tests.c )
target_link_libraries(${PROJECT_TEST} PUBLIC cunit)

#CTest
enable_testing()
add_test(NAME "CunitTest" COMMAND ${PROJECT_TEST})

#Coverage
add_custom_target(cover
COMMAND cmake --build . --target test
COMMAND gcovr -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${PROJECT_TEST}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(cover_html
COMMAND cmake --build . --target test
COMMAND gcovr --html --html-detail -o index.html -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${PROJECT_TEST}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

