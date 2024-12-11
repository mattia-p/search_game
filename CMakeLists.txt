# cmake_minimum_required(VERSION 3.22.1)
# project(demo VERSION 0.1.0)

# # Tells CMake that the project is using C++
# set(CMAKE_CXX_STANDARD 11)
# # ensures that the specified C++ standard (CMAKE_CXX_STANDARD) is required.
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # tells CMake to build an executable from the specified source files 
# add_executable(game src/main.cpp src/Game.cpp src/TextureManager.cpp src/GameObject.cpp src/Map.cpp src/astar.cpp src/Node.cpp)

# # specify the libraries that should be linked to a specific target (such as an executable or a library) during the build process.
# target_link_libraries(game SDL2main SDL2 SDL2_image)

# # specify the directories in which the compiler should search for header files when building a specific target
# target_include_directories(game PUBLIC include/)

# # enable the testing infrastructure provided by CMake in your project
# enable_testing()

# # include another CMake project (or a subdirectory within the same project) into the current project.
# add_subdirectory(tests)


# ----------------------------

cmake_minimum_required(VERSION 3.22.1)
project(demo VERSION 0.1.0)

# Tells CMake that the project is using C++
set(CMAKE_CXX_STANDARD 17)
# Ensures that the specified C++ standard (CMAKE_CXX_STANDARD) is required.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a library target for the game source files
add_library(game_library
  src/Game.cpp
  src/TextureManager.cpp
  src/GameObject.cpp
  src/Map.cpp
  src/astar.cpp
  src/Node.cpp
  src/Button.cpp
)

# Specify include directories for the library target
target_include_directories(game_library PUBLIC include/)

# Link the SDL2 libraries to the game_library
target_link_libraries(game_library
  PRIVATE
  SDL2main
  SDL2
  SDL2_image
)

# Create an executable target for the game
add_executable(game
  src/main.cpp
)

# Link the game executable to the game_library
target_link_libraries(game PRIVATE game_library)

# enable the testing infrastructure provided by CMake in your project
enable_testing()

# include another CMake project (or a subdirectory within the same project) into the current project.
add_subdirectory(tests)
