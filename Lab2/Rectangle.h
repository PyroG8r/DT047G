// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-23
// "kortfattat vad filen innehåller"


#ifndef LAB2_RECTANGLE_H
#define LAB2_RECTANGLE_H


#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double width, double height, std::string color);
    std::string getColor();
    double getArea();
protected:
    double width;
    double height;
};


#endif //LAB2_RECTANGLE_H
