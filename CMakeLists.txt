set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

cmake_minimum_required(VERSION 3.23 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 23)

project(SimpleHttpClient)

find_package(Boost REQUIRED)

add_executable(BoostBeastClient src/boost_beast.cpp)

target_include_directories(BoostBeastClient PRIVATE ${Boost_INCLUDE_DIRS})

find_package(httplib CONFIG REQUIRED)
message(STATUS "${httplib_INCLUDE_DIRS}")

add_executable(CppHttplibClient src/cpp_httplib.cpp)

target_link_libraries(CppHttplibClient PRIVATE httplib::httplib)

