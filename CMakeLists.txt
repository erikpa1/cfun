cmake_minimum_required(VERSION 3.26)
project(cfun LANGUAGES C CXX)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup(TARGETS)


set(CMAKE_GENERATOR_PLATFORM "x64" CACHE STRING "" FORCE)

set(CMAKE_CXX_STANDARD 23)

#find_package(GLFW)f

include(${CMAKE_CURRENT_SOURCE_DIR}/build/conan_toolchain.cmake)

find_package(glfw3)
#target_link_libraries(... glfw)
find_package(glad)
#find_package(CURL)



add_executable(cfun main.cpp
        apps/dungeon/world.cpp
        apps/dungeon/dungeon_app.cpp
        apps/dungeon/prelude.h
        json/parser.c
        apps/sims/singe_server_queuing_system.c
        mat/lcgrand.c
        cmd/cmd.cpp
        apps/vulkanfun/vulkan_entry.cpp
)
target_include_directories(cfun PUBLIC apps/dungeon)
#target_link_libraries(${PROJECT_NAME} CURL::libcurl)
#target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)
#target_link_libraries(${PROJECT_NAME} PRIVATE glfw::glfw)

#target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
target_link_libraries(cfun glfw glad::glad)
