cmake_minimum_required(VERSION 3.0)
project(Game)

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1-Compiled/include/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1-Compiled/lib")
set(SFML_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1-Compiled/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
include_directories(include)

add_executable(space main.cpp)

find_package(SFML 2.5.1 COMPONENTS system window graphics)

add_subdirectory(src/Adapters)
add_subdirectory(src/Artist)
add_subdirectory(src/Asteroids)
add_subdirectory(src/BaseObject)
add_subdirectory(src/Bullet)
add_subdirectory(src/Factories)
add_subdirectory(src/Player)
add_subdirectory(src/SpecialEffects)

#find_package(GTest REQUIRED)

#include_directories(${GTEST_INCLUDE_DIRS})

#add_executable(PlayerTests PlayerTests.cpp tests.cpp src/Player.h src/Player.cpp)

#target_link_libraries(PlayerTests gtest gtest_main)

target_link_libraries(space sfml-graphics sfml-system sfml-window player ordinary_asteroid_factory bullet artist)
