cmake_minimum_required(VERSION 3.23)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2 main.cpp Shape.cpp Shape.h Rectangle.cpp Rectangle.h Circle.cpp Circle.h Cylinder.cpp Cylinder.h Parallelepiped.cpp Parallelepiped.h RoundRectangle.cpp RoundRectangle.h)
