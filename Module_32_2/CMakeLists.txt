cmake_minimum_required(VERSION 3.24)
project(Module_32_2)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(Module_32_2 Module_32_2.cpp)

target_link_libraries(Module_32_2 PRIVATE nlohmann_json::nlohmann_json)

