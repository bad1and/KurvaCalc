cmake_minimum_required(VERSION 3.29)
project(calc C)
set(CMAKE_C_STANDARD 17)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

#add_executable(calc test.c)
add_executable(calc main.c)
target_link_libraries(calc ${CURSES_LIBRARIES})

