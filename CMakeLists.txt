# CMakeList.txt : CMake project for graphics-programming, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CURRENT_FILES "")

set(MAJOR_VERSION 0)
set(MINOR_VERSION 1)
set(PATCH_VERSION 0)

project ("graphics-programming")

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
add_executable (graphics-programming "graphics-programming.cpp" "graphics-programming.h")

install(TARGETS ${APPLICATION_NAME}
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib)

message("libs: ${INCLUDES_LIST}")
message("----------------------")
message("links: ${LINKS_LIST}")

target_compile_definitions(graphics-programming PRIVATE
MAJOR_VERSION=${MAJOR_VERSION}
MINOR_VERSION=${MINOR_VERSION}
PATCH_VERSION=${PATCH_VERSION}
APPLICATION_NAME="${APPLICATION_NAME}"
ENGINE_NAME=${ENGINE_NAME})
# TODO: Add tests and install targets if needed.

target_link_libraries(graphics-programming PRIVATE ${LINKS_LIST})
target_include_directories(graphics-programming PRIVATE ${INCLUDES_LIST})
target_compile_options(graphics-programming PRIVATE ${CFLAGS_LIST})
