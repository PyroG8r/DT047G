// "Shape inheritance", DT047G
// Emil Jons 
// Circle.cpp, 2022-11-23
// "Implementation för Circle klassen"


#include "Circle.h"

Circle::Circle(double radius, std::string color) : radius(radius), Shape(color){

}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

