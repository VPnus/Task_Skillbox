cmake_minimum_required(VERSION 3.24)
project(Module_33_1)

set(CMAKE_CXX_STANDARD 17)

set(Boost_INCLUDE_DIR "C:\\boost_1_83_0")
set(Boost_LIBRARY_DIR "C:\\boost_1_83_0\\stage\\lib")
find_package(Boost COMPONENTS REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(Module_33_1 Module_33_1.cpp)
target_link_libraries(Module_33_1 ${Boost_LIBRARIES})

if(MINGW)
    target_link_libraries(Module_33_1 ws2_32)
endif()
