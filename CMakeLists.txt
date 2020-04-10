cmake_minimum_required(VERSION 3.15)
project(TP_project)

set(CMAKE_CXX_STANDARD 20)

set(SFML_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1/include/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib")
set(SFML_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

#find_package(GTest REQUIRED)

#include_directories(${GTEST_INCLUDE_DIRS})

add_executable(PlayerTests PlayerTests.cpp tests.cpp src/Player.h src/Player.cpp)

#target_link_libraries(PlayerTests gtest gtest_main)

add_executable(TP_project src/Player.cpp src/Player.h src/Object.cpp src/Object.h main.cpp src/OrdinaryAsteroid.cpp src/OrdinaryAsteroid.h src/SmallAsteroid.cpp src/SmallAsteroid.h src/ObjectFactory.cpp src/ObjectFactory.h src/OrdinaryAsteroidFactory.cpp src/OrdinaryAsteroidFactory.h src/SmallAsteroidFactory.cpp src/SmallAsteroidFactory.h)

target_link_libraries(TP_project sfml-graphics sfml-audio sfml-system sfml-network sfml-window)