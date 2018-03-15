cmake_minimum_required(VERSION 2.8)
project(SQLite)
set (CMAKE_CXX_STANDARD 11)


include_directories(.)

SET(PROJ_FILES
    SQLite.cpp
    shell.c
    sqlite3.c
)

add_library(${PROJECT_NAME} ${PROJ_FILES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} pthread)