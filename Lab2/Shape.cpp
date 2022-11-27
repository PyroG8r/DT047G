// "Shape inheritance", DT047G
// Emil Jons 
// Shape.cpp, 2022-11-23
// "Implementaioner för shape klassen"

#include "Shape.h"

#include <utility>

Shape::Shape(std::string color) : color(std::move(color)) {

}
std::string Shape::getColor() const {
    return color;
}


