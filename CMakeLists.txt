cmake_minimum_required(VERSION 3.10)
project(SnakeGame VERSION 1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SNAKE_SOURCES
        src/snake.cpp
)

set(RANDOM_INT_SOURCES
        src/randomInt.cpp
)

set(FIELD_SOURCES
        src/field.cpp
)

set(GAME_SOURCES
        src/game.cpp
)

add_library(Snake STATIC ${SNAKE_SOURCES})
add_library(RandomInt STATIC ${RANDOM_INT_SOURCES})
add_library(Field STATIC ${FIELD_SOURCES})
add_library(Game STATIC ${GAME_SOURCES})

target_link_libraries(Field PRIVATE Snake RandomInt)
target_link_libraries(Game PRIVATE Field)

if(WIN32)
    target_link_libraries(Game PRIVATE user32 gdi32)
endif()

add_executable(SnakeGame main.cpp)

target_link_libraries(SnakeGame PRIVATE Game)
