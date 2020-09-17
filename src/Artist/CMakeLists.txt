project(artist)

set(artist-source-files "${PROJECT_SOURCE_DIR}/Artist.cpp")

add_library(
	artist SHARED ${artist-source-files} ${Game_SOURCE_DIR}/include/Artist/Artist.h
)

target_link_libraries(artist sfml-graphics base_object bullet player)

add_dependencies(artist sfml-graphics base_object bullet player)
