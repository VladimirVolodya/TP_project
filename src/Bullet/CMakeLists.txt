project(bullet)

set(bullet-source-files "${PROJECT_SOURCE_DIR}/Bullet.cpp")

add_library(
	bullet SHARED ${bullet-source-files} ${Game_SOURCE_DIR}/include/Bullet/Bullet.h
)

target_link_libraries(bullet base_object)

add_dependencies(bullet base_object)
