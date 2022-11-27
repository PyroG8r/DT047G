// "Shape inheritance", DT047G
// Emil Jons
// RoundedRectangle.cpp, 2022-11-24
// "Implementaioner för roundedrectangle klassen"


#include "RoundRectangle.h"

RoundRectangle::RoundRectangle(double width, double height, double radius, std::string color)
: Rectangle(width, height, color), radius(radius) {}



double RoundRectangle::getArea() const {
    return Rectangle::getArea() - (radius * radius) * (4 - M_PI);
}
