cmake_minimum_required(VERSION 3.0)
project(TP_project)

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1-Compiled/include/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1-Compiled/lib")
set(SFML_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1-Compiled/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

add_executable(TP_project src/Player.cpp src/Player.h src/Object.cpp src/Object.h main.cpp src/OrdinaryAsteroid.cpp src/OrdinaryAsteroid.h src/SmallAsteroid.cpp src/SmallAsteroid.h src/ObjectFactory.cpp src/ObjectFactory.h src/OrdinaryAsteroidFactory.cpp src/OrdinaryAsteroidFactory.h src/Artist.cpp src/Artist.h src/SpecialEffect.h src/HydraEffect.cpp src/HydraEffect.h src/SmallAsteroidAdapter.cpp src/SmallAsteroidAdapter.h src/FreezeEffect.cpp src/FreezeEffect.h src/Bullet.cpp src/Bullet.h src/BulletAdapter.cpp src/BulletAdapter.h src/FrozenAsteroidFactory.cpp src/FrozenAsteroidFactory.h)

find_package(SFML 2.5.1 COMPONENTS system window graphics)

#find_package(GTest REQUIRED)

#include_directories(${GTEST_INCLUDE_DIRS})

#add_executable(PlayerTests PlayerTests.cpp tests.cpp src/Player.h src/Player.cpp)

#target_link_libraries(PlayerTests gtest gtest_main)

target_link_libraries(TP_project sfml-graphics sfml-audio sfml-system sfml-network sfml-window)
