cmake_minimum_required(VERSION 3.26)
project(cfun LANGUAGES C CXX)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup(TARGETS)

set(CMAKE_CXX_STANDARD 23)

#find_package(GLFW)f

find_package(GLFW)
find_package(GLAD)
#find_package(CURL)

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
        apps/vulkanfun/vulkan_entry.cpp
        apps/vulkanfun/vulkan_entry.h
)
#target_link_libraries(${PROJECT_NAME} CURL::libcurl)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)
#target_link_libraries(${PROJECT_NAME} PRIVATE glfw::glfw)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
