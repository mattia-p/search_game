# Find Google Test
find_package(GTest REQUIRED)

# Create a test executable target
add_executable(my_tests
  test_astar.cpp
)

# Link with Google Test and YourLibrary
target_link_libraries(my_tests gtest gtest_main game_library)

# Specify include directories for Google Test headers and your project's headers
target_include_directories(my_tests PRIVATE ${GTEST_INCLUDE_DIRS})
target_include_directories(my_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
