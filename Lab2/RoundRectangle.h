// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-24
// "kortfattat vad filen innehåller"


#ifndef LAB2_ROUNDRECTANGLE_H
#define LAB2_ROUNDRECTANGLE_H

#include "Rectangle.h"
#include "math.h"


class RoundRectangle : Rectangle {
public:
    RoundRectangle(double width, double height, double radius, std::string color);
    std::string getColor();
    double getArea();
private:
    double radius;
};


#endif //LAB2_ROUNDRECTANGLE_H
