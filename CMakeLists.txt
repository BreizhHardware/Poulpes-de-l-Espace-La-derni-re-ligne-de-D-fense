cmake_minimum_required(VERSION 3.18)

project(Poulpes_de_l_espace_La_derniere_ligne_de_defense LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql Gui Core Multimedia)

file(GLOB_RECURSE sourceCode src/*.cpp src/*.h)

qt_standard_project_setup()

add_executable(Poulpes_de_l_espace_La_derniere_ligne_de_defense ressources.qrc ${sourceCode}
)

target_link_libraries(Poulpes_de_l_espace_La_derniere_ligne_de_defense PRIVATE Qt6::Widgets Qt6::Sql Qt6::Gui Qt6::Core Qt6::Multimedia)
