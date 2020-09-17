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
find_package(GTest)

IF(GTest_FOUND)
    add_executable(tests tests.cpp main_tests.cpp)
    target_link_libraries(
            tests
            player
            small_asteroid_adapter
            bullet_adapter
            small_asteroid
            ordinary_asteroid
            bullet
            ordinary_asteroid_factory
            frozen_asteroid_factory
            freeze_effect
            hydra_effect
            artist
            timer
            ${GTEST_LIBRARIES}
            ${GMOCK_BOTH_LIBRARIES}
            Threads::Threads)
    add_dependencies(
            tests
            player
            small_asteroid_adapter
            bullet_adapter
            small_asteroid
            ordinary_asteroid
            bullet
            ordinary_asteroid_factory
            frozen_asteroid_factory
            freeze_effect
            hydra_effect
            timer)
    include_directories(${GTEST_INCLUDE_DIRS})
ENDIF()

add_subdirectory(src/Adapters)
add_subdirectory(src/Artist)
add_subdirectory(src/Asteroids)
add_subdirectory(src/BaseObject)
add_subdirectory(src/Bullet)
add_subdirectory(src/Factories)
add_subdirectory(src/Player)
add_subdirectory(src/SpecialEffects)
add_subdirectory(src/Timer)

target_link_libraries(space sfml-graphics sfml-system sfml-window player ordinary_asteroid_factory frozen_asteroid_factory bullet artist timer)
