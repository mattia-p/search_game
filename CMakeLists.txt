cmake_minimum_required(VERSION 3.22.1)
project(demo VERSION 0.1.0)

# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

add_executable(game src/main.cpp src/Game.cpp src/TextureManager.cpp src/GameObject.cpp src/Map.cpp src/astar.cpp src/Node.cpp)
target_link_libraries(game SDL2main SDL2 SDL2_image)
target_include_directories(game PRIVATE include/)