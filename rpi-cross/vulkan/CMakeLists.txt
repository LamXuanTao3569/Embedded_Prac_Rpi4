cmake_minimum_required(VERSION 3.10)
project(VulkanAnimation)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(VulkanAnimation main.cpp)
target_link_libraries(VulkanAnimation Vulkan::Vulkan glfw)
