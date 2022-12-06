// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-24
// "kortfattat vad filen innehåller"


#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(double width, double height, double depth, std::string color)
: Rectangle(width, height, color), depth(depth) {}

double Parallelepiped::getArea() const {
    return 2 * width * height + 2 * depth * height + 2 * width * depth;
}

