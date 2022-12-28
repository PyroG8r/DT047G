cmake_minimum_required(VERSION 3.24)
project(Projekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt SourceFiles/main.cpp SourceFiles/Cube.cpp SourceFiles/Cube.h SourceFiles/MovingCube.cpp SourceFiles/MovingCube.h SourceFiles/CubeTower.cpp SourceFiles/CubeTower.h SourceFiles/FixedCube.cpp SourceFiles/FixedCube.h SourceFiles/Game.cpp SourceFiles/Game.h SourceFiles/Constants.h SourceFiles/Sound.cpp SourceFiles/Sound.h SourceFiles/Menu.cpp SourceFiles/Menu.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics window system audio REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Projekt sfml-graphics sfml-window sfml-system sfml-audio)
