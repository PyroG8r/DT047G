// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-23
// "kortfattat vad filen innehåller"


#include "Circle.h"

std::string &Circle::getColor() const {
    return Shape::getColor();
}

float &Circle::getArea() const {
    return Shape::getArea();
}
