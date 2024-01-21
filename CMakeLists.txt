cmake_minimum_required(VERSION 3.26)
project(cfun LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)


add_executable(cfun main.cpp
        apps/dungeon/world.h
        apps/dungeon/world.cpp
        apps/dungeon/dungeon_app.cpp
        apps/dungeon/dungeon_app.h
        apps/dungeon/prelude.h
        meta/class.h
        json/parser.c
        json/parser.h
        json/prelude.h
        mat/lcgrand.h
        apps/sims/singe_server_queuing_system.h
        apps/sims/singe_server_queuing_system.c
        mat/lcgrand.c
        cmd/cmd.h
        cmd/cmd.cpp
        meta/meta.h
)
