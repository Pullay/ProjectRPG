cmake_minimum_required(VERSION 3.16)

project(ProjectRPG)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

find_package(SDL2 REQUIRED)
include_directories(SYSTEM ${SDL2_INCLUDE_DIR})
find_package(SDL2_image REQUIRED)
include_directories(SYSTEM ${SDL_IMAGE_INCLUDE_DIR})
find_package(SDL2_mixer REQUIRED)
include_directories(SYSTEM ${SDL_MIXER_INCLUDE_DIR})
find_package(SDL2_ttf REQUIRED)
include_directories(SYSTEM ${SDLTTF_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
    SDL2_image::SDL2_image
    SDL2_mixer::SDL2_mixer
    SDL2_ttf::SDL2_ttf
)

file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)
