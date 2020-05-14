project(adapters)

set(bullet_adapter-source-files "${PROJECT_SOURCE_DIR}/BulletAdapter.cpp")
set(small_asteroid_adapter-source-files "${PROJECT_SOURCE_DIR}/SmallAsteroidAdapter.cpp")

add_library(
    bullet_adapter SHARED ${bullet_adapter-source-files} ${Game_SOURCE_DIR}/include/Adapters/BulletAdapter.h
)
add_library(
    small_asteroid_adapter SHARED ${small_asteroid_adapter-source-files} ${Game_SOURCE_DIR}/include/Adapters/SmallAsteroidAdapter.h
)

target_link_libraries(bullet_adapter bullet)
target_link_libraries(small_asteroid_adapter small_asteroid)

add_dependencies(bullet_adapter bullet)
