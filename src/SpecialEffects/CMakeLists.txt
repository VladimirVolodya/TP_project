project(special_effects)

set(freeze_effect-source-files "${PROJECT_SOURCE_DIR}/FreezeEffect.cpp")
set(hydra_effect-source-files "${PROJECT_SOURCE_DIR}/HydraEffect.cpp")

add_library(
	freeze_effect SHARED ${freeze_effect-source-files}
				${Game_SOURCE_DIR}/include/SpecialEffects/FreezeEffect.h
				${Game_SOURCE_DIR}/include/SpecialEffects/SpecialEffect.h
)

add_library(
	hydra_effect SHARED ${hydra_effect-source-files}
				${Game_SOURCE_DIR}/include/SpecialEffects/HydraEffect.h
				${Game_SOURCE_DIR}/include/SpecialEffects/SpecialEffect.h
)

target_link_libraries(freeze_effect base_object)
target_link_libraries(hydra_effect base_object small_asteroid_adapter)

add_dependencies(freeze_effect base_object)
add_dependencies(hydra_effect base_object)
