cmake_minimum_required(VERSION 3.10)
project(3D_Animation CXX)

set(CMAKE_CXX_COMPILER "aarch64-linux-gnu-g++")
set(CMAKE_SYSROOT "~/rpi-sysroot")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")

include_directories(
    ${CMAKE_SYSROOT}/usr/include
    ${CMAKE_SYSROOT}/usr/include/SDL2
)
link_directories(
    ${CMAKE_SYSROOT}/usr/lib
)

add_executable(animation main.cpp shader.cpp texture.cpp)
target_link_libraries(animation SDL2 SDL2_image GLESv2 glapi m)
