cmake_minimum_required(VERSION 3.13)
project(NHF2)

set(CMAKE_CXX_STANDARD 11)

add_executable(NHF2 test.cpp Item.h Entity.cpp Entity.h Monster.cpp Monster.h Player.cpp Player.h Tile.cpp Tile.h memtrace.cpp memtrace.h Game.cpp Game.h)