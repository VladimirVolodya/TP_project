project(timer)

set(timer-source-files "${PROJECT_SOURCE_DIR}/Timer.cpp")

add_library(
        timer SHARED ${timer-source-files} ${Game_SOURCE_DIR}/include/Timer/Timer.h
)
