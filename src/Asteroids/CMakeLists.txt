project(asteroids)

set(ordinary_asteroid-source-files "${PROJECT_SOURCE_DIR}/OrdinaryAsteroid.cpp")
set(small_asteroid-source-files "${PROJECT_SOURCE_DIR}/SmallAsteroid.cpp")

add_library(
	ordinary_asteroid SHARED ${ordinary_asteroid-source-files}
				 ${Game_SOURCE_DIR}/include/Asteroids/OrdinaryAsteroid.h
				 ${Game_SOURCE_DIR}/include/SpecialEffects/SpecialEffect.h
)

add_library(
	small_asteroid SHARED ${small_asteroid-source-files} ${Game_SOURCE_DIR}/include/Asteroids/SmallAsteroid.h
)

target_link_libraries(ordinary_asteroid base_object)
target_link_libraries(small_asteroid ordinary_asteroid)

add_dependencies(ordinary_asteroid base_object)
