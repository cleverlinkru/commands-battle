cmake_minimum_required(VERSION 3.10)

project(CommandBattle CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_UNITY_BUILD TRUE)

file(GLOB MY_SOURCES "src/*.cpp")

add_executable(CommandBattle main.cpp ${MY_SOURCES})

target_link_libraries(CommandBattle PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)