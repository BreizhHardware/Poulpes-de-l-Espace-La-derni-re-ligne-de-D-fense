cmake_minimum_required(VERSION 3.18)

project(Poulpes_de_l_espace_La_derniere_ligne_de_defense LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql Gui Core)

file(GLOB_RECURSE sourceCode src/*.cpp src/*.h)

qt_standard_project_setup()

add_executable(Poulpes_de_l_espace_La_derniere_ligne_de_defense ${sourceCode}
        src/Tile.cpp
        src/Tile.h
        src/Map.cpp
        src/Map.h
        src/Menu.cpp
        src/Menu.h
        src/Game.cpp
        src/Game.h
        src/Rules.cpp
        src/Rules.h
        src/Leaderboard.cpp
        src/Leaderboard.h
        src/Mob.cpp
        src/Mob.h
        src/Enemy.cpp
        src/Enemy.h
        src/Player.cpp
        src/Player.h
        src/Gameover.cpp
        src/Gameover.h
        src/Tower.cpp
        src/Tower.h
        src/PlayerDeadException.cpp
        src/PlayerDeadException.h
        src/Projectile.cpp
        src/Projectile.h)

target_link_libraries(Poulpes_de_l_espace_La_derniere_ligne_de_defense PRIVATE Qt6::Widgets Qt6::Sql)
