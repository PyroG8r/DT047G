// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-24
// "kortfattat vad filen innehåller"


#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(double width, double height, double depth, std::string color)
: Rectangle(width, height, color), depth(depth) {}

std::string Parallelepiped::getColor() {
    return Rectangle::getColor();
}

double Parallelepiped::getArea() {
    return Rectangle::getArea() * depth;
}

