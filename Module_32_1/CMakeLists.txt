cmake_minimum_required(VERSION 3.24)
project(Module_32_1)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(Module_32_1 Module_32_1.cpp)

target_link_libraries(Module_32_1 PRIVATE nlohmann_json::nlohmann_json)
