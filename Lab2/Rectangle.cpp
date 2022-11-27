// "Shape inheritance", DT047G
// Emil Jons 
// Rectangle.cpp, 2022-11-23
// "Implementationer för rectangle"


#include "Rectangle.h"

Rectangle::Rectangle(double width, double height, std::string color)
: width(width), height(height), Shape(color){

}



double Rectangle::getArea() const {
    return width * height;
}


