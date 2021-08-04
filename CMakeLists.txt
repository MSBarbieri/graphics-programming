# CMakeList.txt : CMake project for graphics-programming, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)
set(CURRENT_FILES "")

set(MAJOR_VERSION 0)
set(MINOR_VERSION 1)
set(PATCH_VERSION 0)

project ("graphics-programming")
set(CMAKE_CXX_STANDARD 17)
set(INCLUDES_LIST "")
set(LINKS_LIST "")
set(CFLAGS_LIST "")
set(DEFINES_LIST "")

set(THIRD_PARTY_DIR "${PROJECT_SOURCE_DIR}/third_party")
set(ENGINE_LIB_NAME "engine")
set(ENGINE_DIR "${THIRD_PARTY_DIR}/${ENGINE_LIB_NAME}")
add_subdirectory(${ENGINE_DIR})

get_directory_property(INCLUDES_LIST DIRECTORY ${ENGINE_DIR} DEFINITION INCLUDES_LIST)
get_directory_property(LINKS_LIST DIRECTORY ${ENGINE_DIR} DEFINITION LINKS_LIST)


# Add source to this project's executable.
add_subdirectory(src)