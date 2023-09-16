cmake_minimum_required(VERSION 3.24)
project(Test_JN)

set(CMAKE_CXX_STANDARD 17)

set(PAHO_CPP_DIR path/to/paho.mqtt.cpp-1.0.0)

# Добавьте пути к заголовочным файлам и библиотекам
include_directories(${PAHO_CPP_DIR}/src)
link_directories(${PAHO_CPP_DIR}/build/output)


include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)



add_executable(Test_JN main.cpp)
# Укажите, какие библиотеки необходимо подключить
target_link_libraries(Test_JN paho-mqttpp3)
target_link_libraries(Test_JN PRIVATE cpr::cpr)