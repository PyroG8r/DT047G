// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-24
// "kortfattat vad filen innehåller"


#include "RoundRectangle.h"

RoundRectangle::RoundRectangle(double width, double height, double radius, std::string color)
: Rectangle(width, height, color), radius(radius) {}

std::string RoundRectangle::getColor() {
    return Rectangle::getColor();
}

double RoundRectangle::getArea() {
    return Rectangle::getArea() - (radius * radius) * (4 - M_PI);
}
