cmake_minimum_required(VERSION 3.17)
cmake_policy(SET CMP0072 NEW)

project(bomberman VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-missing-field-initializers")

include_directories(include)
set(ASSETS_DIR assets)
set(SRC_DIR src)

add_executable(bomberman
    ${SRC_DIR}/binds.cpp
    ${SRC_DIR}/bomb.cpp
    ${SRC_DIR}/bot.cpp
    ${SRC_DIR}/core.cpp
    ${SRC_DIR}/gengine.cpp
    ${SRC_DIR}/graphLib.cpp
    ${SRC_DIR}/map.cpp
    ${SRC_DIR}/mapGenerator.cpp
    ${SRC_DIR}/menus.cpp
    ${SRC_DIR}/options.cpp
    ${SRC_DIR}/player.cpp
    ${SRC_DIR}/pos.cpp
    ${SRC_DIR}/powerUp.cpp
    ${SRC_DIR}/saveManager.cpp
    ${SRC_DIR}/timer.cpp)

find_package(raylib REQUIRED)
target_link_libraries(bomberman raylib)