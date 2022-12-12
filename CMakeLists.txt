cmake_minimum_required(VERSION 3.20.0)
set(BOARD qemu_cortex_m3)

find_package(Zephyr)
project(zephyrtest)

include_directories(src)
file(GLOB_RECURSE SRCS src/**.cpp)
target_sources(app PRIVATE ${SRCS})