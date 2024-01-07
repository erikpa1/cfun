cmake_minimum_required(VERSION 3.26)
project(cfun C)

set(CMAKE_C_STANDARD 23)

add_executable(cfun main.c
        data/dungeon.h
        data/dungeon.c
        data/dungeon_app.c
        data/dungeon_app.h
        meta/class.h
        json/parser.c
        json/parser.h
        json/prelude.h
        data/prelude.h
)
