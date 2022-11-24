// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-23
// "kortfattat vad filen innehåller"


#include "Circle.h"

Circle::Circle(double radius, std::string color) : radius(radius), Shape(color){

}

std::string Circle::getColor() {
    return Shape::getColor();
}

double Circle::getArea() {
    return M_PI * radius * radius;
}

