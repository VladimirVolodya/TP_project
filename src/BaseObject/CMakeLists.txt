project(base_object)

set(base_object-source-files "${PROJECT_SOURCE_DIR}/Object.cpp")

add_library(
	base_object SHARED ${base_object-source-files} ${Game_SOURCE_DIR}/include/BaseObject/Object.h
)
