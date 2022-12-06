// "Shape inheritance", DT047G
// Emil Jons 
// Cylinder.cpp, 2022-11-24
// "Implementation för cylinder klassen"


#include "Cylinder.h"

Cylinder::Cylinder(double radius, double height, std::string color): Circle(radius, color), height(height){}

double Cylinder::getArea() const {
    return radius * 2 * M_PI * height;
}

