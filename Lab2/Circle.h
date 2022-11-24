// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-23
// "kortfattat vad filen innehåller"


#ifndef LAB2_CIRCLE_H
#define LAB2_CIRCLE_H


#include "Shape.h"
#include "math.h"

class Circle : Shape {
public:
    Circle(double radius, std::string color);
    std::string getColor();
    double getArea();
private:

    double radius;
};


#endif //LAB2_CIRCLE_H
