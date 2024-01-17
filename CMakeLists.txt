cmake_minimum_required(VERSION 3.26)
project(cfun C)

set(CMAKE_C_STANDARD 23)

add_executable(cfun main.c
        apps/dungeon/dungeon.h
        apps/dungeon/dungeon.c
        apps/dungeon/dungeon_app.c
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
)
