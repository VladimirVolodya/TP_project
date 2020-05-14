project(player)

set(player-source-files "${PROJECT_SOURCE_DIR}/Player.cpp")

add_library(
	player SHARED ${player-source-files} ${Game_SOURCE_DIR}/include/Player/Player.h
)

target_link_libraries(player base_object bullet_adapter)

add_dependencies(player base_object)
