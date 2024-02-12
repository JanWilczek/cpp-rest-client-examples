set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(SimpleHttpClient)

find_package(Boost REQUIRED)

add_executable(SimpleHttpClient src/main.cpp)

target_include_directories(SimpleHttpClient PRIVATE ${Boost_INCLUDE_DIRS})
