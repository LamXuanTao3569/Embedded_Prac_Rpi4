cmake_minimum_required(VERSION 3.10)
project(2D_Animation CXX)

set(CMAKE_CXX_COMPILER "aarch64-linux-gnu-g++")
set(CMAKE_SYSROOT "~/rpi-sysroot")

include_directories(
    ${CMAKE_SYSROOT}/usr/include
    ${CMAKE_SYSROOT}/usr/include/SDL2
)
link_directories(
    ${CMAKE_SYSROOT}/usr/lib
)

add_executable(animation animation.cpp)
target_link_libraries(animation SDL2 GLESv2 glapi m)
