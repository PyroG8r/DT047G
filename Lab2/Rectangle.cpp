// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-23
// "kortfattat vad filen innehåller"


#include "Rectangle.h"

std::string &Rectangle::getColor() const {
    return Shape::getColor();
}

float &Rectangle::getArea() const {
    return Shape::getArea();
}
