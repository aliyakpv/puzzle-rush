cmake_minimum_required(VERSION 3.11)
project(puzzle_rush C CXX)

set(CMAKE_CXX_STANDARD 17)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) 
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) 

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG ae50bfa2cc569c0f8d5bc4315d39db64005b1b08
)

FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} raylib)