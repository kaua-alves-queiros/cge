cmake_minimum_required(VERSION 3.10)
project(cge C)

include_directories(include)

add_executable(cge source/main.c source/game_object.c)