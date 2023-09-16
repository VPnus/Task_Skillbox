cmake_minimum_required(VERSION 3.24)
project(module_32_3)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(module_32_3 Module_32_3.cpp)

target_link_libraries(module_32_3 PRIVATE nlohmann_json::nlohmann_json)

