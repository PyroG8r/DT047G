// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-23
// "kortfattat vad filen innehåller"


#include "Shape.h"

#include <utility>


Shape::Shape(std::string color) : color(std::move(color)) {

}
std::string Shape::getColor()  {
    return color;
}


