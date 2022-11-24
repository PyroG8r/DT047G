// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-24
// "kortfattat vad filen innehåller"


#include "Cylinder.h"

Cylinder::Cylinder(double radius, double height, std::string color): Circle(radius, color), height(height){}

double Cylinder::getArea() {
    return Circle::getArea() * height;
}

std::string Cylinder::getColor() {
    return Circle::getColor();
}
