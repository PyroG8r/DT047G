// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-23
// "kortfattat vad filen innehåller"


#include "Rectangle.h"

Rectangle::Rectangle(double width, double height, std::string color)
: width(width), height(height), Shape(color){

}

std::string Rectangle::getColor()  {
    return Shape::getColor();
}

double Rectangle::getArea()  {
    return width * height;
}


