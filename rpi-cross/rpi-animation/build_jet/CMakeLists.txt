cmake_minimum_required(VERSION 3.10)
project(2D_Animation CXX)

set(CMAKE_CXX_COMPILER "aarch64-linux-gnu-g++")
set(CMAKE_SYSROOT "/home/taolam/rpi-cross/rpi-animation/build_jet/sysroot")

include_directories(
    /home/taolam/rpi-cross/rpi-animation/build_jet/sysroot/include
    /home/taolam/rpi-cross/rpi-animation/build_jet/sysroot/include/SDL2
    /home/taolam/rpi-cross/rpi-animation/build_jet/sysroot/include/GLES2
    /home/taolam/rpi-cross/rpi-animation/build_jet/sysroot/include/KHR
)
link_directories(
    /home/taolam/rpi-cross/rpi-animation/build_jet/sysroot/lib
)

add_executable(animation animation.cpp)
target_link_libraries(animation SDL2 GLESv2 EGL)
