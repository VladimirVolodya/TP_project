project(factories)

set(frozen_asteroid_factory-source-files "${PROJECT_SOURCE_DIR}/FrozenAsteroidFactory.cpp")
set(ordinary_asteroid_factory-source-files "${PROJECT_SOURCE_DIR}/OrdinaryAsteroidFactory.cpp")

add_library(
	frozen_asteroid_factory SHARED ${frozen_asteroid_factory-source-files}
				       ${Game_SOURCE_DIR}/include/Factories/ObjectFactory.h
				       ${Game_SOURCE_DIR}/include/Factories/FrozenAsteroidFactory.h
)

add_library(
	ordinary_asteroid_factory SHARED ${ordinary_asteroid_factory-source-files}
					 ${Game_SOURCE_DIR}/include/Factories/ObjectFactory.h
					 ${Game_SOURCE_DIR}/include/Factories/OrdinaryAsteroidFactory.h
)

target_link_libraries(ordinary_asteroid_factory ordinary_asteroid hydra_effect)
target_link_libraries(frozen_asteroid_factory ordinary_asteroid freeze_effect)

add_dependencies(ordinary_asteroid_factory hydra_effect)
add_dependencies(frozen_asteroid_factory freeze_effect)
